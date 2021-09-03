use chrono;
use core::fmt::Arguments;
use fern::{Dispatch, FormatCallback};
use log::*;

/*
 * Possible logging functions:
 * trace
 * debug
 * info
 * warn
 * error
 */

// The logger uses no file for its output, but forwards all logs to the stdout or stderr
// This is as the daemon functionality already forwards all output into files
pub fn setup_logger() {
    match Dispatch::new()
        .format(set_formatting)
        .chain(get_dispatcher_non_error())
        .chain(get_dispatcher_error())
        .apply()
    {
        Ok(_reply) => (),
        Err(err) => eprintln!(
            "Error: {} \nCouldn't initialize logger. Program will continue without logging facilities.",
            err
        ),
    };
}

fn set_formatting(out: FormatCallback, message: &Arguments, record: &Record) {
    out.finish(format_args!(
        "{}[{}][{}] {}",
        chrono::Local::now().format("[%Y-%m-%d][%H:%M:%S]"),
        record.level(),
        record.module_path().unwrap(),
        message
    ));
}

fn get_dispatcher_non_error() -> Dispatch {
    fern::Dispatch::new()
        .level(log::LevelFilter::Trace)
        .chain(std::io::stdout())
}

fn get_dispatcher_error() -> Dispatch {
    fern::Dispatch::new()
        .level(log::LevelFilter::Error)
        .chain(std::io::stderr())
}
