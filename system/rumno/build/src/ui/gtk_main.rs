use crate::common::config::Config;
use crate::ui::app::App;
use crate::ui::message::Message;

use glib;

use log::*;
use std::process;

pub fn run_gtk(receiver: glib::Receiver<Message>) {
    let config = Config::default().unwrap_or_else(|e| {
        error!("{}", e);
        process::exit(1);
    });

    match App::new(config) {
        Err(e) => {
            error!("{}", e);
            process::exit(1);
        }
        Ok(app) => {
            app.update_notification(receiver);
            app.run();
        }
    }
}
