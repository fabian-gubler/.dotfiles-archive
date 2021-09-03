use crate::common::constants;
use std::string::String;

#[derive(Serialize, Deserialize, Debug, Clone, PartialEq)]
pub enum NotificationImageType {
    Play,
    Pause,
    Previous,
    Next,
    Brightness,
    VolumeLow,
    VolumeMedium,
    VolumeHigh,
    VolumeOff,
    VolumeMuted,
    CustomSymbol(String),
}

impl NotificationImageType {
    pub fn get_file_name(&self) -> String {
        match self {
            NotificationImageType::Play => constants::ICON_FILE_PLAY.to_string(),
            NotificationImageType::Pause => constants::ICON_FILE_PAUSE.to_string(),
            NotificationImageType::Previous => constants::ICON_FILE_PREVIOUS_SONG.to_string(),
            NotificationImageType::Next => constants::ICON_FILE_NEXT_SONG.to_string(),
            NotificationImageType::Brightness => constants::ICON_FILE_BRIGHTNESS.to_string(),
            NotificationImageType::VolumeLow => constants::ICON_FILE_VOL_LOW.to_string(),
            NotificationImageType::VolumeMedium => constants::ICON_FILE_VOL_MEDIUM.to_string(),
            NotificationImageType::VolumeHigh => constants::ICON_FILE_VOL_HIGH.to_string(),
            NotificationImageType::VolumeOff => constants::ICON_FILE_VOL_OFF.to_string(),
            NotificationImageType::VolumeMuted => constants::ICON_FILE_VOL_MUTED.to_string(),
            NotificationImageType::CustomSymbol(icon_name) => icon_name.clone(),
        }
    }

    pub fn get_image_as_bytes(&self) -> &[u8] {
        match self {
            NotificationImageType::Play => constants::ICON_BYTES_PLAY,
            NotificationImageType::Pause => constants::ICON_BYTES_PAUSE,
            NotificationImageType::Previous => constants::ICON_BYTES_PREVIOUS_SONG,
            NotificationImageType::Next => constants::ICON_BYTES_NEXT_SONG,
            NotificationImageType::Brightness => constants::ICON_BYTES_BRIGHTNESS,
            NotificationImageType::VolumeLow => constants::ICON_BYTES_VOL_LOW,
            NotificationImageType::VolumeMedium => constants::ICON_BYTES_VOL_MEDIUM,
            NotificationImageType::VolumeHigh => constants::ICON_BYTES_VOL_HIGH,
            NotificationImageType::VolumeOff => constants::ICON_BYTES_VOL_OFF,
            NotificationImageType::VolumeMuted => constants::ICON_BYTES_VOL_MUTED,
            NotificationImageType::CustomSymbol(_) => &[],
        }
    }
}
