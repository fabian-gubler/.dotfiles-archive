use crate::common::config::Config;

// Used to communicate between UI thread and other threads
#[derive(Debug)]
pub enum Message {
    UpdateUI(Config),
}
