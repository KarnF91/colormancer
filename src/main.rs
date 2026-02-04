use std::fmt;
use std::io;
use std::io::{Write};

fn read_line(prompt: &str) -> String {
    print!("{prompt}");
    io::stdout().flush().unwrap();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

/* TODO: Better error handling.  Prevent entering integers larger than 255.
 * allow for entering R,G,B instead of asking for each value.
 * allow for entering as RGB
 * allow for enter 0xRRGGBB
 * allow for enter other methods.
 */

fn read_u8(prompt: &str) -> u8 {
    loop {
        let input = read_line(prompt);
        if let Ok(num) = input.parse() {
            return num;
        }
    }
}

struct Color {
    red: u8,
    green: u8,
    blue: u8,
}

impl fmt::Display for Color {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "Color: RGB({}, {}, {}) #{:02X}{:02X}{:02X}\x1b[48;2;{};{};{}m       \x1b[0m", self.red, self.green, self.blue, self.red, self.green, self.blue, self.red, self.green, self.blue)
    }
}

fn main() {
    let mut colors = Color { red: 0, green: 0, blue: 0 };

    colors.red = read_u8("Enter R Value: ");
    colors.green = read_u8("Enter G Value: ");
    colors.blue = read_u8("Enter B Value: ");

    println!("{}", colors);
}
