use std::io;

fn main() {
    let mut s: String = String::new();

    io::stdin().read_line(&mut s).unwrap();

    let year: i32 = s.trim().parse().unwrap();

    println!("{}", year - 2541 + 1998);
}
