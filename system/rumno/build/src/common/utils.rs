use num::Integer;
use std::cell::RefCell;
use std::rc::Rc;

// Create a tuple from a vector
// TODO Make this return an option
pub fn gen_tuple_from_vec<T: Clone>(input: std::vec::Vec<T>) -> (T, T) {
    (input[0].clone(), input[1].clone())
}

pub fn gen_array_from_vec<T: Clone>(input: std::vec::Vec<T>) -> Option<[T; 4]> {
    if input.len() < 4 {
        None
    } else {
        Some([input[0].clone(), input[1].clone(), input[2].clone(), input[3].clone()])
    }
}

// Splits a string into parts of 2. It assumes the string has the structure of a hex code
pub fn split_hex_color_code(hex_str: &str) -> std::vec::Vec<&str> {
    let mut v = vec![];
    let mut cur = hex_str;
    while !cur.is_empty() {
        let (chunk, rest) = cur.split_at(std::cmp::min(2, cur.len()));
        v.push(chunk);
        cur = rest;
    }
    v
}

pub fn hex_string_to_vec(hex_str: &str) -> std::result::Result<std::vec::Vec<u32>, std::num::ParseIntError> {
    let color_split_hex = split_hex_color_code(hex_str);
    color_split_hex.iter().map(|&s| u32::from_str_radix(s, 16)).collect()
}

pub trait InRange {
    fn in_range(&self, begin: Self, end: Self) -> bool;
}

impl InRange for f64 {
    fn in_range(&self, begin: f64, end: f64) -> bool {
        *self >= begin && *self < end
    }
}

pub fn increment_counter<T>(c: &Rc<RefCell<T>>)
where
    T: Integer + Copy,
{
    let new_c = *c.borrow() + T::one();
    c.replace(new_c);
}

pub fn decrement_counter<T>(c: &Rc<RefCell<T>>)
where
    T: Integer + Copy,
{
    let new_c = *c.borrow() - T::one();
    c.replace(new_c);
}
