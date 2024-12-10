fn main() {
    let str = get_input();
    let length = str.len();
    println!("{}", length);
}

fn get_input() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
