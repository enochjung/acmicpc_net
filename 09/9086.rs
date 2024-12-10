fn main() {
    let t = get_tc_input();

    for _ in 0..t {
        let str = get_input();
        let (first, last) = get_answer(str);
        println!("{}{}", first as char, last as char);
    }
}

fn get_tc_input() -> u32 {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().parse::<u32>().unwrap()
}

fn get_input() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn get_answer(str: String) -> (u8, u8) {
    let bytes = str.as_bytes();
    (bytes[0], bytes[str.len() - 1])
}
