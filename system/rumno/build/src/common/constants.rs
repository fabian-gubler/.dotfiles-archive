// This file contains all constants used to define the program
// Could be transformed into a proper config file that could be read out during startup
// instead of during compile time

//////////////////////////////
// config relevant - defines how Rumno will look like
// general settings
pub static DIMENSIONS: (i64, i64) = (250, 200);
pub static TIMEOUT: &str = "1.0"; // s
pub static CORNER_RADIUS: &str = "0.2";
pub static BAR_NUM_SEGMENTS: &str = "20";
pub static MAX_INPUT_LEVEL: &str = "100";
pub static INPUT_LEVEL: f64 = 0.;
pub static BAR_FILLED_COLOR: &str = "D1E5E1";
pub static BAR_EMPTY_COLOR: &str = "D1E5E140";
pub static BAR_SEGMENT_RATIO: &str = "1.0";
pub static BAR_OVERREACH_COLOR: &str = "B00B1E";
pub static BACKGROUND_COLOR: &str = "101010A0";
pub static ICON_HEIGHT: &str = "0.5"; // in percentage to the entire notification

// Those are not too relevant, they are not part of the cli yet
pub static ICON_TOP_MARGIN: f64 = 0.33;
pub static BAR_MARGIN_X: f64 = 0.1;
pub static BAR_SEGMENT_MARGIN_X: f64 = 0.2;

// image files
pub static ICONS_DIR: &str = "/usr/share/rumno/res";
pub static ICON_FILE_VOL_LOW: &str = "volume_low.svg";
pub static ICON_FILE_VOL_MEDIUM: &str = "volume_medium.svg";
pub static ICON_FILE_VOL_HIGH: &str = "volume_high.svg";
pub static ICON_FILE_VOL_OFF: &str = "volume_off.svg";
pub static ICON_FILE_VOL_MUTED: &str = "volume_muted.svg";
pub static ICON_FILE_BRIGHTNESS: &str = "brightness.svg";
pub static ICON_FILE_PREVIOUS_SONG: &str = "previous_song.svg";
pub static ICON_FILE_NEXT_SONG: &str = "next_song.svg";
pub static ICON_FILE_PAUSE: &str = "pause.svg";
pub static ICON_FILE_PLAY: &str = "play.svg";

// images at compile time loaded into binary
pub static ICON_BYTES_VOL_LOW: &[u8] = include_bytes!("../../res/volume_low.svg");
pub static ICON_BYTES_VOL_MEDIUM: &[u8] = include_bytes!("../../res/volume_medium.svg");
pub static ICON_BYTES_VOL_HIGH: &[u8] = include_bytes!("../../res/volume_high.svg");
pub static ICON_BYTES_VOL_OFF: &[u8] = include_bytes!("../../res/volume_off.svg");
pub static ICON_BYTES_VOL_MUTED: &[u8] = include_bytes!("../../res/volume_muted.svg");
pub static ICON_BYTES_BRIGHTNESS: &[u8] = include_bytes!("../../res/brightness.svg");
pub static ICON_BYTES_PREVIOUS_SONG: &[u8] = include_bytes!("../../res/previous_song.svg");
pub static ICON_BYTES_NEXT_SONG: &[u8] = include_bytes!("../../res/next_song.svg");
pub static ICON_BYTES_PAUSE: &[u8] = include_bytes!("../../res/pause.svg");
pub static ICON_BYTES_PLAY: &[u8] = include_bytes!("../../res/play.svg");

//////////////////////////////
// dbus relevant
pub static DBUS_BUS_NAME: &str = "de.rumno.v1";
pub static DBUS_PATH: &str = "/Rumno";
pub static DBUS_INTERFACE: &str = "de.Rumno";
pub static DBUS_METHOD_UPDATE_CONFIG: &str = "updateConfig";
pub static DBUS_METHOD_UPDATE_INPUT_ARG: &str = "newConfiguration";
pub static DBUS_METHOD_UPDATE_OUTPUT_ARG: &str = "reply";
pub static DBUS_TIMEOUT_SEND_METHOD: i32 = 2000; //ms

//////////////////////////////
// daemon relevant
pub static LOG_PATH: &str = "/tmp/rumno";
pub static OUTPUT_LOG_FILE: &str = "rumno.out";
pub static ERROR_LOG_FILE: &str = "rumno.err";
pub static PID_FILE: &str = "rumno.pid";
