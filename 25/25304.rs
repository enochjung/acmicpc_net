use std::io;

fn main() {
    let (total_cost, items) = get_input();
    println!(
        "{}",
        if is_correct(total_cost, items) {
            "Yes"
        } else {
            "No"
        }
    );
}

fn is_correct(total_cost: i32, items: Vec<(i32, i32)>) -> bool {
    let sum = items.iter().fold(0, |sum, (price, num)| sum + price * num);
    return sum == total_cost;
}

fn get_input() -> (i32, Vec<(i32, i32)>) {
    let mut s: String = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let total_cost: i32 = s.trim().parse().unwrap();

    let mut s: String = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let n: i32 = s.trim().parse().unwrap();

    let mut items: Vec<(i32, i32)> = Vec::new();
    for _ in 0..n {
        let mut s: String = String::new();
        io::stdin().read_line(&mut s).unwrap();

        let values: Vec<i32> = s
            .as_mut_str()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        items.push((values[0], values[1]));
    }

    return (total_cost, items);
}
