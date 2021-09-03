use crate::common::config::Config;
use crate::ui::image_loader::ImageLoader;

use log::*;
use std::f64::consts::PI;

use gtk::prelude::*;

// This module contains all relevant code to draw the notification

// The main drawing method, which in turn calls drawing methods for the different parts of the notification
pub fn draw(ctx: &cairo::Context, config: &Config) -> Inhibit {
    draw_background(ctx, config);
    draw_icon(ctx, config);
    if config.show_bar {
        draw_progress_bar(ctx, config);
    }

    Inhibit(false)
}

fn draw_background(ctx: &cairo::Context, config: &Config) {
    let window_width = config.width as f64;
    let window_height = config.height as f64;

    ctx.set_antialias(cairo::Antialias::Best);

    ctx.save();

    ctx.scale(window_width, window_height);

    let cr = config.corner_radius;
    let window_ratio = window_width / window_height;
    let degrees = PI / 180.0;

    // Draw the rounded rectangle
    // Scale is used to accomodate for symmetric corners in a non-quadratic rectangle
    ctx.scale(1. / window_ratio, 1.);

    ctx.new_sub_path();
    ctx.arc(cr, 1.0 - cr, cr, 90.0 * degrees, 180.0 * degrees);
    ctx.arc(cr, cr, cr, 180.0 * degrees, 270.0 * degrees);
    ctx.arc(1.0 * window_ratio - cr, cr, cr, 270.0 * degrees, 0.0 * degrees);
    ctx.arc(1.0 * window_ratio - cr, 1.0 - cr, cr, 0.0 * degrees, 90.0 * degrees);
    ctx.close_path();

    set_source_rgba(ctx, config.background_color);
    ctx.fill();

    ctx.restore();
}

fn draw_icon(ctx: &cairo::Context, config: &Config) {
    let window_width = config.width as f64;
    let window_height = config.height as f64;

    let image_loader = ImageLoader::new(&config);

    match image_loader.get_image() {
        Some(icon) => {
            let offset_x = (window_width - icon.get_width() as f64) * 0.5;
            let offset_y = (window_height - icon.get_height() as f64) * config.icon_top_margin;
            ctx.set_source_surface(&icon, offset_x, offset_y);
            ctx.paint();
        }
        None => error!("Couldn't load icon!"),
    };
}

fn draw_progress_bar(ctx: &cairo::Context, config: &Config) {
    let window_width = config.width as f64;
    let window_height = config.height as f64;

    // Calculate all relevant metrics
    let mut offset_x = config.bar_margin_x * window_width;

    let width_bar = window_width - 2. * offset_x;
    let width_segment_with_space = width_bar / config.bar_num_segments as f64;
    let width_segment = width_segment_with_space * (1. - config.bar_segment_margin_x);
    let height_segment = width_segment / config.bar_segment_ratio;

    let mut width_filled = offset_x + width_bar * config.level_perc;

    // In case the level is more than 100%, the filled width is too large calculated
    if config.level_perc > 1. {
        width_filled -= width_bar;
    }

    // Center the bar in the space below the icon
    let icon_height = window_height * config.icon_height;
    let y_pos_icon_bottom = icon_height + (window_height - icon_height) * config.icon_top_margin;
    let offset_y = y_pos_icon_bottom + (window_height - y_pos_icon_bottom - height_segment * 2.) * 0.5;

    // Draw the progress bar
    for _i in 0..config.bar_num_segments {
        let color = get_bar_color(offset_x, width_filled, &config);
        set_source_rgba(ctx, color);
        ctx.rectangle(offset_x, offset_y, width_segment, height_segment);
        ctx.fill();
        offset_x += width_segment_with_space;
    }
}

// Returns the right color for each bar segment
fn get_bar_color(offset_x: f64, width_filled: f64, config: &Config) -> [f64; 4] {
    if config.level_perc > 1. {
        if config.overreach {
            if offset_x < width_filled {
                config.bar_overreach_color
            } else {
                config.bar_filled_color
            }
        } else {
            config.bar_filled_color
        }
    } else if offset_x < width_filled {
        config.bar_filled_color
    } else {
        config.bar_empty_color
    }
}

// Helper function to directly use an array of four f64
fn set_source_rgba(ctx: &cairo::Context, color: [f64; 4]) {
    ctx.set_source_rgba(color[0], color[1], color[2], color[3]);
}
