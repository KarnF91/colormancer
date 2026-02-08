use std::fmt;
use std::io;
use std::io::{Write};

/* TODO: Better error handling.  Prevent entering integers larger than 255.
 * Currently able to input R,G,B.  But values about 255 are allowed.
 * Need to account for the user to input R G B, or R, G, B
 * Need to figure out how to convert the string to u8.
 * allow for entering as RGB
 * allow for enter 0xRRGGBB
 * allow for enter other methods.
 */

fn read_input(prompt: &str) -> Vec<u8> {
    print!("{prompt}");
    io::stdout().flush().unwrap();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let input_vec: Vec<u8> = input.trim().split(',').filter_map(|s| s.trim().parse().ok()).collect();
    input_vec
}

/*fn read_line(prompt: &str) -> String {
    print!("{prompt}");
    io::stdout().flush().unwrap();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}*/


/*fn read_u8(prompt: &str) -> u8 {
    loop {
        let input = read_line(prompt);
        if let Ok(num) = input.parse() {
            return num;
        }
    }
}*/

struct Color {
    red: u8,
    green: u8,
    blue: u8,
}

impl fmt::Display for Color {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "Color: RGB({}, {}, {}) #{:02X}{:02X}{:02X} \x1b[48;2;{};{};{}m       \x1b[0m", self.red, self.green, self.blue, self.red, self.green, self.blue, self.red, self.green, self.blue)
    }
}

fn main() {
    let mut colors = Color { red: 0, green: 0, blue: 0 };

    let input_value = read_input("Enter a R,G,B value: ");

    colors.red = input_value[0];
    colors.green = input_value[1];
    colors.blue = input_value[2];

    println!("{}", colors);
}
