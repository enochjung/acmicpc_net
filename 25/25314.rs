use std::io;

fn main() {
    let n: u32 = get_input();
    println!("{}int", "long ".repeat(usize::try_from(n / 4).unwrap()));
}

fn get_input() -> u32 {
    let mut s: String = String::new();

    io::stdin().read_line(&mut s).unwrap();
    let n: u32 = s.trim().parse().unwrap();

    return n;
}
