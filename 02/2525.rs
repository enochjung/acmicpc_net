use std::io;

fn main() {
    let (hour, minute, duration) = get_input();

    let time: i32 = hour * 60 + minute + duration;
    let time: i32 = time % (24 * 60);
    let hour: i32 = time / 60;
    let minute: i32 = time % 60;

    println!("{} {}", hour, minute);
}

fn get_input() -> (i32, i32, i32) {
    let mut input_line: String = String::new();

    io::stdin().read_line(&mut input_line).unwrap();
    io::stdin().read_line(&mut input_line).unwrap();

    let values: Vec<i32> = input_line
        .as_mut_str()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    return (values[0], values[1], values[2]);
}
