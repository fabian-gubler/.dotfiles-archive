// This module provides functionality to send a config file as a byte sequence through the dbus

use crate::common::config::Config;
use crate::common::constants;

use bincode;
use dbus::{BusType, Connection, Message};

use std::error::Error;

pub fn send_config(config: &Config) -> Result<&str, Box<dyn Error>> {
    let bytes_to_send: Vec<u8> = bincode::serialize(config).unwrap();

    let c = Connection::get_private(BusType::Session)?;

    let m = create_message(bytes_to_send);

    match c.send_with_reply_and_block(m, constants::DBUS_TIMEOUT_SEND_METHOD) {
        Ok(reply) => check_reply_for_success(reply),
        Err(err) => Err(Box::new(err)),
    }
}

fn create_message(bytes_to_send: Vec<u8>) -> Message {
    Message::new_method_call(
        constants::DBUS_BUS_NAME,
        constants::DBUS_PATH,
        constants::DBUS_INTERFACE,
        constants::DBUS_METHOD_UPDATE_CONFIG,
    )
    .unwrap()
    .append1(bytes_to_send)
}

fn check_reply_for_success(reply: Message) -> Result<&'static str, Box<dyn Error>> {
    if reply.msg_type() == dbus::MessageType::MethodReturn {
        Ok("Success!")
    } else {
        Err(Box::new(dbus::Error::new_custom(
            constants::DBUS_BUS_NAME,
            "Message was received by daemon, but the message content was not understood",
        )))
    }
}
