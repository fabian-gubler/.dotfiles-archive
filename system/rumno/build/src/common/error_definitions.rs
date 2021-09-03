use std::error::Error;
use std::fmt;

// Custom error definition
#[derive(Debug, Clone)]
pub struct CustomError {
    msg: String,
}

impl CustomError {
    pub fn new(msg: &str) -> CustomError {
        CustomError { msg: msg.to_string() }
    }
}

impl fmt::Display for CustomError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", self.msg)
    }
}

impl Error for CustomError {
    fn source(&self) -> Option<&(dyn Error + 'static)> {
        None
    }
}

// CLI error definition
#[derive(Serialize, Deserialize, Debug)]
pub struct CliError {
    details: String,
    option: String,
}

impl CliError {
    pub fn new(msg: &str, op: &str) -> CliError {
        CliError {
            option: op.to_string(),
            details: msg.to_string(),
        }
    }
}

impl fmt::Display for CliError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "Wrong argument for option '{}': {}", self.details, self.option)
    }
}

impl Error for CliError {
    fn description(&self) -> &str {
        &self.details
    }
}
