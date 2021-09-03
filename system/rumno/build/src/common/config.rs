use clap::{App, Arg, ArgGroup};

use crate::common::constants;
use crate::common::error_definitions::CliError;
use crate::common::utils;
use crate::common::utils::InRange; // custom implementation for type f64
use crate::ui::notification_image_type::NotificationImageType;

#[derive(Serialize, Deserialize, Debug, Clone)]
pub struct Config {
    pub width: f64,
    pub height: f64,
    pub timeout: u32,
    pub corner_radius: f64,
    pub icon_height: f64,
    pub icon_top_margin: f64,
    pub icon_file_directory: Option<std::string::String>,
    pub image_type: NotificationImageType,
    pub show_bar: bool,
    pub level_perc: f64,
    pub overreach: bool,
    pub bar_num_segments: u32,
    pub bar_segment_ratio: f64,
    pub bar_margin_x: f64,
    pub bar_segment_margin_x: f64,
    pub bar_filled_color: [f64; 4],
    pub bar_empty_color: [f64; 4],
    pub bar_overreach_color: [f64; 4],
    pub background_color: [f64; 4],
}

impl Config {
    pub fn new() -> Result<Config, CliError> {
        let matches = Self::define_cli_parser().get_matches();
        Self::construct_config_from_matches(&matches)
    }

    // Used mainly for testing, creates a default configuration object
    pub fn default() -> Result<Config, CliError> {
        let arg_vec = vec!["rumno", "-v", "50"];
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        Self::construct_config_from_matches(&matches)
    }

    pub fn compute_image_path(&self) -> Option<std::string::String> {
        if let Some(ref dir) = self.icon_file_directory {
            let file = self.image_type.get_file_name();
            let image_path = format!("{}/{}", dir, file);
            Some(image_path)
        } else {
            match &self.image_type {
                NotificationImageType::CustomSymbol(image_path) => Some(image_path.to_string()),
                _ => None,
            }
        }
    }

    // Creates the configuration object from the matches object created by clap
    // Seperating this step enables the easy creation of a default object
    fn construct_config_from_matches(matches: &clap::ArgMatches) -> Result<Config, CliError> {
        let dimensions = Self::get_dimensions(matches)?;
        let width = dimensions.0 as f64;
        let height = dimensions.1 as f64;

        let timeout = Self::get_timeout(matches)?;

        let corner_radius = Self::get_corner_radius(matches)?;

        let overreach = Self::get_overreach(matches);

        let bar_num_segments = Self::get_bar_num_segments(matches)?;
        let max_input_level = Self::get_max_input_level(matches)?;
        let current_level = Self::get_current_level(matches)?;
        let level_perc = current_level / max_input_level;
        let bar_segment_ratio = Self::get_bar_segment_ratio(matches)?;

        let bar_margin_x = constants::BAR_MARGIN_X;
        let bar_segment_margin_x = constants::BAR_SEGMENT_MARGIN_X;

        let icon_height = Self::get_icon_height(matches)?;
        let icon_file_directory = Self::get_icon_directory(matches);
        let image_type = Self::get_notification_image_type(level_perc, matches)?;
        let mut icon_top_margin = constants::ICON_TOP_MARGIN;

        let show_bar = Self::get_show_bar(matches);
        if !show_bar {
            // Center icon if no bar is shown
            icon_top_margin = 0.5;
        }

        let bar_filled_color = Self::get_bar_filled_color(matches)?;
        let bar_empty_color = Self::get_bar_empty_color(matches)?;
        let bar_overreach_color = Self::get_bar_overreach_color(matches)?;
        let background_color = Self::get_background_color(matches)?;

        Ok(Config {
            width,
            height,
            timeout,
            corner_radius,
            icon_file_directory,
            image_type,
            icon_height,
            icon_top_margin,
            show_bar,
            bar_num_segments,
            level_perc,
            bar_segment_ratio,
            bar_margin_x,
            bar_segment_margin_x,
            overreach,
            bar_filled_color,
            bar_empty_color,
            bar_overreach_color,
            background_color,
        })
    }

    // Definition of the parser seperated in its own function for easier testing
    fn define_cli_parser<'a, 'b>() -> clap::App<'a, 'b> {
        App::new("Rumno")
            .usage("rumno <--muted|--brightness-level <FLOAT>|--volume-level <FLOAT>>")
            .version("v0.1")
            .about("Volume and Brightness Notification Manager")
            .arg(Arg::with_name("dimensions")
                .help("Expects 2 arguments, specifying the width and height of the displayed notification window. Both numbers must be integers")
                .short("d")
                .long("dimensions")
                .value_names(&["INT", "INT"])
                .multiple(true))
            .arg(Arg::with_name("corner_radius")
                .help("Specifies curvature strength of the corners of the notification window. Must be in range from 0 to 1")
                .short("r")
                .long("corner-radius")
                .value_name("FLOAT")
                .default_value(constants::CORNER_RADIUS))
            .arg(Arg::with_name("timeout")
                .help("Notification timeout in seconds")
                .short("t")
                .long("timeout")
                .value_name("FLOAT")
                .default_value(constants::TIMEOUT))
            .arg(Arg::with_name("icon_height")
                .help("Specifies the height of the icon in relation to the total height of the notification window. Must be in range from 0 to 1")
                .long("icon-height")
                .value_name("FLOAT")
                .default_value(constants::ICON_HEIGHT))
            .arg(Arg::with_name("icons_dir")
                .help("Specifies the directory containing all icon files")
                .long("icons-dir")
                .value_name("STRING"))
            .arg(Arg::with_name("bar_num_segments")
                .help("Specifies the number of segments in the progress bar")
                .long("bar-num-segments")
                .value_name("INT")
                .default_value(constants::BAR_NUM_SEGMENTS))
            .arg(Arg::with_name("bar_segment_ratio")
                .help("Specifies the ratio between width and height of each segment of the bar. A ratio of 1.0 would result in squared segments. A ratio higher below 1.0 would result in a higher than wide segment")
                .long("bar-segment-ratio")
                .value_name("float")
                .default_value(constants::BAR_SEGMENT_RATIO))
            .arg(Arg::with_name("max_input_level")
                .help("Maximal expected input level. If overreach is not turned off, an input level higher than this value will be shown, up to an extend of 200% of this value")
                .long("max-input-level")
                .value_name("FLOAT")
                .default_value(constants::MAX_INPUT_LEVEL))
            .arg(Arg::with_name("volume_level")
                .help("Display specified volume level. Default maximum value is 100")
                .long("volume-level")
                .short("v")
                .value_name("FLOAT"))
            .arg(Arg::with_name("brightness_level")
                .help("Display specified brightness level. Default maximum value is 100")
                .long("brightness-level")
                .short("b")
                .value_name("FLOAT"))
            .arg(Arg::with_name("background_color")
                .help("background color")
                .long("background-color")
                .value_name("RRGGBBAA")
                .default_value(constants::BACKGROUND_COLOR))
            .arg(Arg::with_name("bar_filled_color")
                .help("color of the filled segments in the bar")
                .long("bar-filled-color")
                .value_name("RRGGBBAA")
                .default_value(constants::BAR_FILLED_COLOR))
            .arg(Arg::with_name("bar_empty_color")
                .help("color of the not filled segments in the bar")
                .long("bar-empty-color")
                .value_name("RRGGBBAA")
                .default_value(constants::BAR_EMPTY_COLOR))
            .arg(Arg::with_name("bar_overreach_color")
                .help("color of the segments in the bar which are field the second time due to a level of over 100%")
                .long("bar-overreach-color")
                .value_name("RRGGBBAA")
                .default_value(constants::BAR_OVERREACH_COLOR))
            .arg(Arg::with_name("overreach-off")
                .help("turn off overreaching, which is the display of levels above 100%")
                .long("overreach-off"))
            .arg(Arg::with_name("next_song")
                .help("show next song notification")
                .short("n")
                .long("next"))
            .arg(Arg::with_name("previous_song")
                .help("show previous song notification")
                .short("p")
                .long("previous"))
            .arg(Arg::with_name("pause")
                .help("show pause symbol")
                .long("pause"))
            .arg(Arg::with_name("play")
                .help("show play symbol")
                .long("play"))
            .arg(Arg::with_name("is_muted")
                .help("show muted symbol")
                .short("m")
                .long("muted"))
            .arg(Arg::with_name("custom_symbol")
                .help("Display a custom svg symbol")
                .long("custom-symbol")
                .short("c")
                .value_name("PATH"))
            .group(ArgGroup::with_name("level_info")
                .args(&["is_muted", "brightness_level", "volume_level", "next_song", "previous_song", "play", "pause", "custom_symbol"])
                .required(true))
    }

    fn get_dimensions(matches: &clap::ArgMatches) -> Result<(i64, i64), CliError> {
        match matches.values_of("dimensions") {
            Some(args) => {
                // Extract dimensions as i64 to make sure they are all integers
                // Even though we later on require f64, it must be integers
                match args.map(|val| val.parse::<i64>()).collect() {
                    Ok(dim_vec) => Ok(utils::gen_tuple_from_vec(dim_vec)),
                    Err(_) => Err(CliError::new("-d", "Dimensions must be integers")),
                }
            }
            None => Ok(constants::DIMENSIONS),
        }
    }

    fn get_corner_radius(matches: &clap::ArgMatches) -> Result<f64, CliError> {
        match matches.value_of("corner_radius").unwrap().parse::<f64>() {
            Ok(val) => {
                if val > 0. && val < 1.0 {
                    Ok(val)
                } else {
                    Err(CliError::new("-r", "Specified value must be in range 0.0 to 1.0"))
                }
            }
            Err(_) => Err(CliError::new("-r", "Could not parse given parameter")),
        }
    }

    fn get_timeout(matches: &clap::ArgMatches) -> Result<u32, CliError> {
        match matches.value_of("timeout").unwrap().parse::<f64>() {
            Ok(val) => Ok((val * 1000.) as u32),
            Err(_) => Err(CliError::new("--timeout", "Could not parse given parameter")),
        }
    }

    fn get_icon_height(matches: &clap::ArgMatches) -> Result<f64, CliError> {
        match matches.value_of("icon_height").unwrap().parse::<f64>() {
            Ok(val) => {
                if val > 0. && val < 1.0 {
                    Ok(val)
                } else {
                    Err(CliError::new(
                        "--icon-height",
                        "Specified value must be in range 0.0 to 1.0",
                    ))
                }
            }
            Err(_) => Err(CliError::new("--icon-height", "Could not parse given parameter")),
        }
    }

    fn get_bar_num_segments(matches: &clap::ArgMatches) -> Result<u32, CliError> {
        match matches.value_of("bar_num_segments").unwrap().parse::<u32>() {
            Ok(val) => Ok(val),
            Err(_) => Err(CliError::new("--bar-num-segments", "Could not parse given parameter")),
        }
    }

    fn get_bar_segment_ratio(matches: &clap::ArgMatches) -> Result<f64, CliError> {
        match matches.value_of("bar_segment_ratio").unwrap().parse::<f64>() {
            Ok(val) => {
                if val > 0. {
                    Ok(val)
                } else {
                    Err(CliError::new("--bar-segment-ratio", "Specified value must be positive"))
                }
            }
            Err(_) => Err(CliError::new("--bar-segment-ratio", "Could not parse given parameter")),
        }
    }

    fn get_max_input_level(matches: &clap::ArgMatches) -> Result<f64, CliError> {
        match matches.value_of("max_input_level").unwrap().parse::<f64>() {
            Ok(val) => {
                if val > 0. {
                    Ok(val)
                } else {
                    Err(CliError::new("--max-input-level", "Specified value must be positive"))
                }
            }
            Err(_) => Err(CliError::new("--max-input-level", "Could not parse given parameter")),
        }
    }

    // either muted or a level must be specified. In case muted is specified there will be no value
    // for level, in which case it must use a default value, as a current level must always be
    // specified
    fn get_current_level(matches: &clap::ArgMatches) -> Result<f64, CliError> {
        // Handle all three cases: muted, volume or brightness
        if matches.is_present("volume_level") {
            return match matches.value_of("volume_level").unwrap().parse::<f64>() {
                Ok(val) => Ok(val),
                Err(_) => Err(CliError::new("-v", "Could not parse given parameter")),
            };
        }
        if matches.is_present("brightness_level") {
            return match matches.value_of("brightness_level").unwrap().parse::<f64>() {
                Ok(val) => Ok(val),
                Err(_) => Err(CliError::new("-v", "Could not parse given parameter")),
            };
        }
        // default case if neither volume nor brightness are specified
        Ok(constants::INPUT_LEVEL)
    }

    fn get_overreach(matches: &clap::ArgMatches) -> bool {
        !matches.is_present("overreach-off")
    }

    fn get_background_color(matches: &clap::ArgMatches) -> Result<[f64; 4], CliError> {
        let hex_str = matches.value_of("background_color").unwrap();
        Self::handle_color_string_to_vec(hex_str, "--background-color")
    }

    fn get_bar_filled_color(matches: &clap::ArgMatches) -> Result<[f64; 4], CliError> {
        let hex_str = matches.value_of("bar_filled_color").unwrap();
        Self::handle_color_string_to_vec(hex_str, "--bar-filled-color")
    }

    fn get_bar_empty_color(matches: &clap::ArgMatches) -> Result<[f64; 4], CliError> {
        let hex_str = matches.value_of("bar_empty_color").unwrap();
        Self::handle_color_string_to_vec(hex_str, "--bar-empty-color")
    }

    fn get_bar_overreach_color(matches: &clap::ArgMatches) -> Result<[f64; 4], CliError> {
        let hex_str = matches.value_of("bar_overreach_color").unwrap();
        Self::handle_color_string_to_vec(hex_str, "--bar_overreach-color")
    }

    fn handle_color_string_to_vec(hex_str: &str, cli_parameter: &str) -> Result<[f64; 4], CliError> {
        if hex_str.chars().count() != 6 && hex_str.chars().count() != 8 {
            return Err(CliError::new(
                cli_parameter,
                "Color hex code must be of format RRGGBB or RRGGBBAA",
            ));
        }
        let mut color: std::vec::Vec<f64> = match utils::hex_string_to_vec(hex_str) {
            Ok(vec) => vec.iter().map(|&val| val as f64 / 255.).collect(),
            Err(_) => {
                return Err(CliError::new(
                    cli_parameter,
                    "Color hex code must be of format RRGGBB or RRGGBBAA",
                ))
            }
        };

        // Add transparency if it wasn't specified
        if hex_str.chars().count() == 6 {
            color.push(1.);
        }

        Ok(utils::gen_array_from_vec(color).unwrap())
    }

    fn get_show_bar(matches: &clap::ArgMatches) -> bool {
        matches.is_present("brightness_level") || matches.is_present("volume_level")
    }

    fn get_icon_directory(matches: &clap::ArgMatches) -> Option<std::string::String> {
        match matches.value_of("icons_dir") {
            Some(dir) => Some(dir.to_string()),
            None => None,
        }
    }

    fn get_notification_image_type(
        level_perc: f64,
        matches: &clap::ArgMatches,
    ) -> Result<NotificationImageType, CliError> {
        let notification_image_type = if matches.is_present("custom_symbol") {
            // We expect custom_symbol to contain an absolute path and not to be present in the ressource directory
            match matches.value_of("custom_symbol") {
                Some(file_path) => return Ok(NotificationImageType::CustomSymbol(file_path.to_string())),
                None => return Err(CliError::new("-c, --custom-symbol", "No valid file path provided")),
            }
        } else if matches.is_present("is_muted") {
            NotificationImageType::VolumeMuted
        } else if matches.is_present("brightness_level") {
            NotificationImageType::Brightness
        } else if matches.is_present("previous_song") {
            NotificationImageType::Previous
        } else if matches.is_present("next_song") {
            NotificationImageType::Next
        } else if matches.is_present("pause") {
            NotificationImageType::Pause
        } else if matches.is_present("play") {
            NotificationImageType::Play
        } else {
            match level_perc {
                x if x.in_range(0.0000, 0.0001) => NotificationImageType::VolumeOff,
                x if x.in_range(0.0001, 0.3333) => NotificationImageType::VolumeLow,
                x if x.in_range(0.3333, 0.6666) => NotificationImageType::VolumeMedium,
                x if x.in_range(0.6666, 1.0000) => NotificationImageType::VolumeHigh,
                _ => NotificationImageType::VolumeHigh,
            }
        };
        Ok(notification_image_type)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    macro_rules! assert_f64_eq {
        ($n1:expr, $n2:expr) => {{
            let n1 = $n1;
            let n2 = $n2;
            assert!(
                (n1 - n2).abs() < std::f64::EPSILON,
                "f64 numbers differ by more than machine epsilon: {} {}",
                n1,
                n2
            )
        }};
    }

    #[test]
    fn test_cli_default_dimension() {
        let arg_vec = vec!["rumno", "-v", "50"];
        let exp_dimensions = constants::DIMENSIONS;
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_dimensions = Config::get_dimensions(&matches).unwrap();
        assert_eq!(exp_dimensions, rec_dimensions);
    }

    #[test]
    fn test_cli_dimension() {
        let arg_vec = vec!["rumno", "-v", "50", "-d", "13", "17"];
        let exp_dimensions = (13, 17);
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_dimensions = Config::get_dimensions(&matches).unwrap();
        assert_eq!(exp_dimensions, rec_dimensions);
    }

    #[test]
    fn test_cli_dimensions_bad_input() {
        let arg_vec = vec!["rumno", "-v", "50", "-d", "13.0", "17.5"];
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_dimensions = Config::get_dimensions(&matches);
        assert!(
            rec_dimensions.is_err(),
            "Should throw an error due to non-integer input dimensions"
        );
    }

    #[test]
    fn test_cli_corner_radius_default() {
        let arg_vec = vec!["rumno", "-v", "50"];
        let exp_corner_radius = constants::CORNER_RADIUS.parse::<f64>().unwrap();
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_corner_radius = Config::get_corner_radius(&matches).unwrap();
        assert_f64_eq!(exp_corner_radius, rec_corner_radius);
    }

    #[test]
    fn test_cli_corner_radius() {
        let arg_vec = vec!["rumno", "-v", "50", "-r", "0.4"];
        let exp_corner_radius = 0.4;
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_corner_radius = Config::get_corner_radius(&matches).unwrap();
        assert_f64_eq!(exp_corner_radius, rec_corner_radius);
    }

    #[test]
    fn test_cli_corner_radius_bad_input() {
        let arg_vec = vec!["rumno", "-v", "50", "-r", "1.4"];
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_corner_radius = Config::get_corner_radius(&matches);
        assert!(
            rec_corner_radius.is_err(),
            "Should throw an error due to corner radius out of range"
        );
    }

    #[test]
    fn test_cli_background_color() {
        let arg_vec = vec!["rumno", "-v", "50", "--background-color", "FF000F"];
        let exp_background_color = [1., 0., 15. / 255., 1.0];
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_background_color = Config::get_background_color(&matches).unwrap();
        assert_eq!(exp_background_color, rec_background_color);
    }

    #[test]
    fn test_cli_background_color_too_short_input() {
        let arg_vec = vec!["rumno", "-v", "50", "--background-color", "FFF"];
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_background_color = Config::get_background_color(&matches);
        assert!(
            rec_background_color.is_err(),
            "Should throw an error due to too short color hex code"
        );
    }

    #[test]
    fn test_cli_background_color_long_input() {
        let arg_vec = vec!["rumno", "-v", "50", "--background-color", "FFFFFFFF"];
        let exp_background_color = [1., 1., 1., 1.0];
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_background_color = Config::get_background_color(&matches).unwrap();
        assert_eq!(exp_background_color, rec_background_color);
    }

    #[test]
    fn test_cli_background_color_bad_input() {
        let arg_vec = vec!["rumno", "-v", "50", "--background-color", "AAARAA"];
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_background_color = Config::get_background_color(&matches);
        assert!(
            rec_background_color.is_err(),
            "Should throw an error due to too short color hex code"
        );
    }

    #[test]
    fn test_get_current_level_int() {
        let arg_vec = vec!["rumno", "-v", "100"];
        let exp_level = 100.;
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_level = Config::get_current_level(&matches).unwrap();
        assert_f64_eq!(exp_level, rec_level);
    }

    #[test]
    fn test_get_current_level_float() {
        let arg_vec = vec!["rumno", "-v", "0.1"];
        let exp_level = 0.1;
        let matches = Config::define_cli_parser().get_matches_from(arg_vec);
        let rec_level = Config::get_current_level(&matches).unwrap();
        assert_f64_eq!(exp_level, rec_level);
    }
}
