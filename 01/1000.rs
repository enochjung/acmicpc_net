fn main() {
    let (a, b) = get_input();
    println!("{}", a + b);
}

fn get_input() -> (i32, i32) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut get = || iter.next().unwrap();

    let (a, b) = (get(), get());

    (a, b)
}
