// This module compiles into the binary to start the notification daemon. It receives the
// notification updates through a dbus interface

use rumno::common::daemon::run_this_as_daemon;
use rumno::common::logging::setup_logger;
use rumno::dbus_util;
use rumno::ui::gtk_channel_container::GtkChannelContainer;
use rumno::ui::gtk_main;

use glib;

use std::process;
use std::thread;

fn main() {
    setup_logger();
    run_daemon();
    setup_and_run_main_loop();
}

fn run_daemon() {
    match run_this_as_daemon() {
        Ok(_) => println!("Daemon started successfully"),
        Err(e) => {
            eprintln!("Error: {}", e);
            process::exit(0);
        }
    }
}

fn setup_and_run_main_loop() {
    let (sender, receiver) = glib::MainContext::channel(glib::PRIORITY_DEFAULT);

    thread::spawn(move || {
        let sender = GtkChannelContainer { sender };
        let result = dbus_util::server::setup_dbus_server(sender);

        match result {
            Ok(_reply) => println!("Daemon finished its endless loop for some reason (that's probably bad)"),
            Err(err) => eprintln!("Error: {} \nPlease check if the daemon is running", err),
        };
    });

    gtk_main::run_gtk(receiver);
}
