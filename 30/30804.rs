fn main() {
    let fruits = get_input();
    let answer = get_answer(fruits);
    println!("{}", answer);
}

fn get_input() -> Vec<u8> {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input
        .split_ascii_whitespace()
        .flat_map(str::parse::<u8>)
        .map(|x| x - 1)
        .collect()
}

fn get_answer(fruits: Vec<u8>) -> u32 {
    let mut answer = 0;
    let mut i = 0;

    let mut counter = [0; 9];
    let is_too_much = |x: [u32; 9]| x.iter().filter(|x| **x > 0).count() > 2;

    for j in 0..fruits.len() {
        counter[fruits[j] as usize] += 1;
        while is_too_much(counter) {
            counter[fruits[i] as usize] -= 1;
            i += 1;
        }
        answer = answer.max(j - i + 1);
    }

    answer as u32
}
