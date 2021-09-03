// Starts a daemon with the proper settings for this project.
// Use like this:
//
// match run_this_as_daemon() {
//     Ok(_) => println!("Success, daemonized"),
//     Err(e) => {
//         eprintln!("Error: {}", e);
//         process::exit(0);
//     }
// }

use crate::common::constants;
use crate::common::error_definitions::CustomError;

use daemonize::Daemonize;

use std::error::Error;
use std::fs;
use std::path::Path;

pub fn run_this_as_daemon() -> Result<(), Box<dyn Error>> {
    fs::create_dir_all(constants::LOG_PATH)?;

    let log_output_file = Path::new(constants::LOG_PATH).join(Path::new(constants::OUTPUT_LOG_FILE));
    let stdout = fs::File::create(log_output_file)?;
    let log_error_file = Path::new(constants::LOG_PATH).join(Path::new(constants::ERROR_LOG_FILE));
    let stderr = fs::File::create(log_error_file)?;

    let pid_file = Path::new(constants::LOG_PATH).join(Path::new(constants::PID_FILE));

    let daemonize = Daemonize::new()
        .pid_file(pid_file)
        .chown_pid_file(true) // is optional, see `Daemonize` documentation
        .working_directory(constants::LOG_PATH) // for default behaviour.
        .umask(0o777)
        .stdout(stdout) // Redirect stdout
        .stderr(stderr) // Redirect stderr
        .exit_action(|| println!("Daemon started successfully"));

    match daemonize.start() {
        Ok(_) => Ok(()),
        Err(e) => {
            let err_msg: &str = &format!("{}\nCheck if the Rumno daemon is already running in the background", e)[..];
            Err(Box::new(CustomError::new(err_msg)))
        }
    }
}
