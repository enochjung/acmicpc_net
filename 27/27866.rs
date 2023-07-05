fn main() {
    let (s, i) = get_input();
    println!("{}", s.chars().nth(i - 1).unwrap());
}

fn get_input() -> (String, usize) {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace();
    let mut get = || iter.next().unwrap();

    let s = String::from(get());
    let i = str::parse::<usize>(get()).unwrap();

    (s, i)
}
