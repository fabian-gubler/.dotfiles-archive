// This module runs the 'daemon' and the client at the same time to easily test functionality.
// It does not in fact run as a daemon, but behaves similar

use rumno::common::config::Config;
use rumno::common::logging::setup_logger;
use rumno::dbus_util;
use rumno::ui::gtk_channel_container::GtkChannelContainer;
use rumno::ui::gtk_main;

use glib;

use std::process;
use std::{thread, time};

fn main() {
    setup_logger();
    let (sender, receiver) = glib::MainContext::channel(glib::PRIORITY_DEFAULT);

    thread::spawn(|| {
        send_new_config_delayed(500);
        send_new_config_delayed(2000);
        end_process_delayed(3500);
    });

    thread::spawn(move || {
        let sender = GtkChannelContainer { sender };
        let result = dbus_util::server::setup_dbus_server(sender);

        match result {
            Ok(_reply) => println!("Daemon finished its endless loop for some reason (that's probably bad)"),
            Err(err) => eprintln!("{}\nPlease check if the daemon is running", err),
        };
    });

    gtk_main::run_gtk(receiver);
}

// This will send a new configuration after a certain time for test purposes
fn send_new_config_delayed(delay_ms: u64) {
    let d = time::Duration::from_millis(delay_ms);
    thread::sleep(d);

    println!("Update notification!");

    let config = Config::new().unwrap_or_else(|e| {
        eprintln!("{}", e);
        process::exit(1);
    });

    match dbus_util::client::send_config(&config) {
        Ok(_reply) => println!("Sent notification successfully"),
        Err(err) => eprintln!("{}\nPlease check if the daemon is running", err),
    };
}

fn end_process_delayed(delay_ms: u64) {
    let d = time::Duration::from_millis(delay_ms);
    thread::sleep(d);
    println!("End process successfully");
    process::exit(0);
}
