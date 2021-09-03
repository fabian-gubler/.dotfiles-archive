// This module provides functionality to start the server

use crate::common::config;
use crate::common::constants;

use crate::ui::gtk_channel_container::GtkChannelContainer;
use bincode;
use dbus::tree::{Factory, Interface, MTFn};
use dbus::{BusType, Connection, NameFlag};

use log::*;
use std::error::Error;

// Setting up the dbus server expects a function which will handle received config objects
// The Ok() return value does not matter as this function starts a server that runs endlessly, thus
// no result, but only errors can be thrown during initialization
pub fn setup_dbus_server(channel_container: GtkChannelContainer) -> Result<(), Box<dyn Error>> {
    // Start up a connection to the session bus and register a name
    let c = Connection::get_private(BusType::Session)?;
    c.register_name(constants::DBUS_BUS_NAME, NameFlag::ReplaceExisting as u32)?;

    let f = Factory::new_fn::<()>();

    // Create a tree with one object path inside and make that path introspectable
    let tree = f.tree(()).add(
        f.object_path(constants::DBUS_PATH, ())
            .introspectable()
            .add(create_iface(channel_container)),
    );

    // We register all object paths in the tree.
    tree.set_registered(&c, true).unwrap();

    // We add the tree to the connection so that incoming method calls will be handled
    // automatically during calls to "incoming".
    c.add_handler(tree);

    // Serve other peers forever.
    loop {
        c.incoming(1000).next();
    }
}

fn create_iface(channel_container: GtkChannelContainer) -> Interface<MTFn<()>, ()> {
    let f = Factory::new_fn::<()>();
    f.interface(constants::DBUS_INTERFACE, ()).add_m(
        f.method(constants::DBUS_METHOD_UPDATE_CONFIG, (), move |m| {
            // Read out the serialized config object
            let received_config_bytes: Vec<u8> = m.msg.read1()?;

            // Decode the received byte vector into the config object
            let result_decoded: Result<config::Config, _> = bincode::deserialize(&received_config_bytes[..]);

            // Check if the sent byte decoded object was properly received
            match result_decoded {
                Ok(decoded_config) => {
                    // handle_received_config_fun(decoded_config);
                    channel_container.send(decoded_config);
                    // Return an answer to signify a successful transmission
                    let mret = m.msg.method_return().append1("Success");
                    Ok(vec![mret])
                }
                Err(err) => {
                    error!("Error during serialization: {:?}", err);
                    // Return an answer to signify a failed transmission
                    let mret = m
                        .msg
                        .method_return()
                        .append1("Failed due to wrong serialization of transmitted object");
                    Ok(vec![mret])
                }
            }

            // The method has one output argument and one input argument
        })
        .outarg::<&str, _>(constants::DBUS_METHOD_UPDATE_OUTPUT_ARG)
        .inarg::<Vec<u8>, _>(constants::DBUS_METHOD_UPDATE_INPUT_ARG),
    )
}
