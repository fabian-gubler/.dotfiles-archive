use log::*;
use std::cell::RefCell;
use std::error::Error;
use std::rc::Rc;

use glib;
use gtk::prelude::*;
use gtk::DrawingArea;

use crate::common::config::Config;
use crate::common::utils;
use crate::ui::drawing;
use crate::ui::message::Message;

/*
 * This is the main class keeping everything together
 * The struct App contains the main gtk objects to hide, show and redraw the notification
 * as well as information about the timers to stop the notification.
 * Once the notification is shown a timeout is started, once it finishes the notification gets
 * hidden.
 * There is a counter that is increased every time a new notification is sent in through a channel.
 * Everytime a notification was shown long enough the counter is decreased again. Once the counter
 * reaches 0, the notification is hidden again.
 */

#[derive(Debug)]
pub struct App {
    // config contains all information relevant to create the specified notification
    config: Config,
    // The entire notification is one drawing area, this object enables easy updating
    drawing_area: Rc<gtk::DrawingArea>,
    // Main window displaying the notification
    window: Rc<RefCell<gtk::Window>>,
    timeout_counter: Rc<RefCell<u32>>,
    draw_signal_handler: Rc<RefCell<Option<glib::signal::SignalHandlerId>>>,
}

impl App {
    pub fn new(config: Config) -> Result<Self, Box<dyn Error>> {
        gtk::init()?;

        let drawing_area = Rc::new(DrawingArea::new());
        let timeout_counter = Rc::new(RefCell::new(0));
        let main_window = Self::setup_gui(Rc::clone(&drawing_area), &config);
        let window = Rc::new(RefCell::new(main_window));
        let draw_signal_handler = Rc::new(RefCell::new(None));

        let new_app = Self {
            config,
            drawing_area,
            window,
            timeout_counter,
            draw_signal_handler,
        };

        Ok(new_app)
    }

    pub fn run(&self) {
        gtk::main();
    }

    fn setup_gui(drawing_area: Rc<gtk::DrawingArea>, config: &Config) -> gtk::Window {
        let window = gtk::Window::new(gtk::WindowType::Popup);
        window.set_title("Rumno");
        window.set_default_size(config.width as i32, config.height as i32);

        // Make window a splash screen
        window.set_type_hint(gdk::WindowTypeHint::Notification);
        window.set_position(gtk::WindowPosition::Center);

        // crucial for transparency
        Self::set_visual(&window, None);
        window.connect_screen_changed(Self::set_visual);
        window.set_app_paintable(true);

        window.add(&*drawing_area);

        // TODO why is this not called?
        window.connect_destroy_event(|_, _| {
            info!("Quit main");
            gtk::main_quit();
            Inhibit(false)
        });

        window
    }

    pub fn update_notification(&self, receiver: glib::Receiver<Message>) {
        let cloned_drawing_area = Rc::clone(&self.drawing_area);
        let cloned_timeout_counter = Rc::clone(&self.timeout_counter);
        let cloned_window = Rc::clone(&self.window);
        let cloned_timeout = self.config.timeout;
        let cloned_draw_signal_handler = Rc::clone(&self.draw_signal_handler);
        // The receiver in the function parameters is the end point of a channel to communicate
        // between gui thread and other threads
        receiver.attach(None, move |msg| {
            match msg {
                Message::UpdateUI(config) => {
                    debug!("Received config: {:?}", config);
                    Self::change_window_size(&cloned_window, config.width as i32, config.height as i32);
                    Self::update_timeout(cloned_timeout, &cloned_timeout_counter, &cloned_window);

                    // Remove old function to redraw the notification window
                    let signal_handler_option = cloned_draw_signal_handler.borrow_mut().take();
                    if let Some(s) = signal_handler_option {
                        glib::signal::signal_handler_disconnect(&*cloned_drawing_area, s);
                    }

                    // Draw new notification
                    let draw_signal_handler =
                        cloned_drawing_area.connect_draw(move |_w, ctx| drawing::draw(ctx, &config));
                    cloned_draw_signal_handler.replace(Some(draw_signal_handler));

                    cloned_drawing_area.queue_draw();
                    Self::show_notification(&cloned_window);
                }
            };
            glib::Continue(true)
        });
    }

    // This function updates a counter and starts a timeout. Once the counter reaches zero, the
    // notification will be hidden again
    fn update_timeout(duration: u32, timeout_counter: &Rc<RefCell<u32>>, window: &Rc<RefCell<gtk::Window>>) {
        utils::increment_counter(&timeout_counter);

        // Add new timeout
        let cloned_window = window.clone();
        let cloned_timeout_counter = timeout_counter.clone();
        gtk::timeout_add(duration, move || {
            utils::decrement_counter(&cloned_timeout_counter);

            if *cloned_timeout_counter.borrow() == 0 {
                Self::hide_notification(&cloned_window);
            }
            gtk::Continue(false)
        });
    }

    fn show_notification(window: &Rc<RefCell<gtk::Window>>) {
        window.borrow_mut().show_all();
    }

    fn hide_notification(window: &Rc<RefCell<gtk::Window>>) {
        window.borrow_mut().hide();
    }

    fn change_window_size(window: &Rc<RefCell<gtk::Window>>, width: i32, height: i32) {
        window.borrow_mut().set_default_size(width, height);
    }

    // Crucial for transparency
    fn set_visual(window: &gtk::Window, _screen: Option<&gdk::Screen>) {
        if let Some(screen) = window.get_screen() {
            if let Some(ref visual) = screen.get_rgba_visual() {
                window.set_visual(Some(visual));
            }
        }
    }
}
