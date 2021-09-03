// This module compiles into the main binary to send new notifications
// It transforms the cli commands into a config object which is sent to the notification daemon
// through the dbus

use rumno::common::config::Config;
use rumno::common::logging::setup_logger;
use rumno::dbus_util;

use log::*;
use std::process;

fn main() {
    setup_logger();
    let config = Config::new().unwrap_or_else(|e| {
        error!("{}", e);
        process::exit(1);
    });

    match dbus_util::client::send_config(&config) {
        // Use print instead of logging facility as this message is directly printed into the terminal
        Ok(_reply) => println!("Sent notification successfully"),
        Err(err) => eprintln!("Error: {} \nPlease check if the daemon is running", err),
    };
}
