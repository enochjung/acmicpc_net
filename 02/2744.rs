fn main() {
    let str = get_input();
    let fliped = flip_case(str);
    println!("{}", fliped);
}

fn get_input() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn flip_case(str: String) -> String {
    let vec = str
        .into_bytes()
        .into_iter()
        .map(|x| {
            if x < b'a' {
                x - b'A' + b'a'
            } else {
                x - b'a' + b'A'
            }
        })
        .collect();

    String::from_utf8(vec).unwrap()
}
