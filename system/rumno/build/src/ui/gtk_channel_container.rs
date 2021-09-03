// Experimental crate, to encapsulate the sender object.

use crate::common::config::Config;
use crate::ui::message::Message;

use glib;

use log::*;

pub struct GtkChannelContainer {
    pub sender: glib::Sender<Message>,
}

impl GtkChannelContainer {
    pub fn send(&self, config: Config) {
        match self.sender.send(Message::UpdateUI(config)) {
            Ok(_) => info!("Forwarded message received through dbus successfully"),
            Err(e) => error!("{}", e),
        };
    }
}
