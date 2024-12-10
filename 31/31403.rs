fn main() {
    let (a, b, c) = get_input();

    let res1 = general_result(a, b, c);
    let res2 = weird_result(a, b, c);

    println!("{}", res1);
    println!("{}", res2);
}

fn get_input() -> (i32, i32, i32) {
    let mut input = String::new();

    for _ in 0..3 {
        std::io::stdin().read_line(&mut input).unwrap();
    }

    let v: Vec<_> = input
        .split_whitespace()
        .flat_map(str::parse::<i32>)
        .collect();

    (v[0], v[1], v[2])
}

fn general_result(a: i32, b: i32, c: i32) -> i32 {
    a + b - c
}

fn weird_result(a: i32, b: i32, c: i32) -> i32 {
    let a = a.to_string();
    let b = b.to_string();

    let apb = format!("{}{}", a, b);
    let apb = str::parse::<i32>(&apb).unwrap();

    apb - c
}
