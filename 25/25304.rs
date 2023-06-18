use std::io;

fn main() {
    let mut dice: Vec<i32> = get_input();

    dice.sort();

    let reward: i32 = get_reward(&dice);

    println!("{}", reward)
}

fn get_reward(dice: &Vec<i32>) -> i32 {
    if dice[0] == dice[2] {
        return dice[0] * 1000 + 10000;
    } else if dice[0] == dice[1] || dice[1] == dice[2] {
        return dice[1] * 100 + 1000;
    } else {
        return dice[2] * 100;
    }
}

fn get_input() -> (i32, Vec<(i32, i32)>) {
    let mut s: String = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let total_cost: i32 = s.trim().parse().unwrap();

    let values: Vec<i32> = input_line
        .as_mut_str()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    return (total_cost);
}
