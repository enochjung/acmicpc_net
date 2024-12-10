fn main() {
    let (a, b) = get_input();
    let answer = get_answer(a, b);
    println!("{}", answer);
}

fn get_input() -> (i64, i64) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let v: Vec<_> = input
        .split_whitespace()
        .flat_map(str::parse::<i64>)
        .collect();

    (v[0], v[1])
}

fn get_answer(a: i64, b: i64) -> i64 {
    (a + b) * (a - b)
}
