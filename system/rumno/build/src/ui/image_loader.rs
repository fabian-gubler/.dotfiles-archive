use crate::common::config::Config;
use crate::ui::notification_image_type::NotificationImageType;

use log::*;

use std::process;
use std::string::String;

// Images can come from two origins: Either from in the binary encoded images or from a path
// This struct handles both, so the caller doesn't need to care about the origin
// The ImageLoader uses the Config object to determine what to do. The config.icon_file_directory is an
// Option. If it is None, use the binary images, otherwise, load the images dynamically
#[derive(Debug)]
pub struct ImageLoader<'a> {
    config: &'a Config,
}

impl<'a> ImageLoader<'a> {
    pub fn new(config: &Config) -> ImageLoader {
        ImageLoader { config }
    }

    pub fn get_image(self) -> Option<cairo::ImageSurface> {
        // Ignore the path if it is of type custom symbol, since this should already contain the entire path
        match &self.config.image_type {
            NotificationImageType::CustomSymbol(_) => self.load_icon_from_file(),
            _ => match &self.config.icon_file_directory {
                Some(_dir) => self.load_icon_from_file(),
                None => self.load_icon_from_stack(),
            },
        }
    }

    fn load_icon_from_file(self) -> Option<cairo::ImageSurface> {
        let opt = self.define_svg_options();
        let tree = self.load_tree_from_file(&opt);
        self.render_tree_to_cairo_surface(&tree, &opt)
    }

    fn load_icon_from_stack(self) -> Option<cairo::ImageSurface> {
        let opt = self.define_svg_options();

        let tree = self.load_tree_from_stack(&opt);
        self.render_tree_to_cairo_surface(&tree, &opt)
    }

    fn define_svg_options(&self) -> resvg::Options {
        let mut opt = resvg::Options::default();
        opt.fit_to = resvg::FitTo::Height((self.config.height * self.config.icon_height) as u32);
        opt
    }

    fn render_tree_to_cairo_surface(
        self,
        tree: &resvg::usvg::Tree,
        opt: &resvg::Options,
    ) -> Option<cairo::ImageSurface> {
        resvg::backend_cairo::render_to_image(tree, opt)
    }

    fn load_tree_from_file(&self, opt: &resvg::Options) -> resvg::usvg::Tree {
        let file_path = self
            .config
            .compute_image_path()
            .unwrap_or_else(|| String::from("default.svg"));
        debug!("Load icon from path {:?}", file_path);

        match resvg::usvg::Tree::from_file(&file_path, &opt.usvg) {
            Ok(val) => val,
            Err(e) => {
                error!("{}", e);
                process::exit(1); //TODO throw error instead of ending entire process
            }
        }
    }

    fn load_tree_from_stack(&self, opt: &resvg::Options) -> resvg::usvg::Tree {
        let bytes = self.config.image_type.get_image_as_bytes();
        debug!("Load icon from data");

        match resvg::usvg::Tree::from_data(&bytes[..], &opt.usvg) {
            Ok(val) => val,
            Err(e) => {
                error!("{}", e);
                process::exit(1); //TODO throw error instead of ending entire process
            }
        }
    }
}
