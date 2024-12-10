fn main() {
    let input = get_input();
    let num = get_next_number(input);
    let str = to_fizzbuzz(num);
    println!("{}", str);
}

fn get_input() -> [Option<u32>; 3] {
    let mut arr = [None; 3];

    for i in 0..3 {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        arr[i] = input.trim().parse::<u32>().map_or(None, Some);
    }

    arr
}

fn get_next_number(arr: [Option<u32>; 3]) -> u32 {
    arr.into_iter()
        .enumerate()
        .flat_map(|(i, num)| num.and_then(|x| Some(x + 3 - i as u32)))
        .next()
        .unwrap()
}

fn to_fizzbuzz(num: u32) -> String {
    let is_multiple_3 = num % 3 == 0;
    let is_multiple_5 = num % 5 == 0;

    if is_multiple_3 || is_multiple_5 {
        format!(
            "{}{}",
            if is_multiple_3 { "Fizz" } else { "" },
            if is_multiple_5 { "Buzz" } else { "" }
        )
    } else {
        num.to_string()
    }
}
