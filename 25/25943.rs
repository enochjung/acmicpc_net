fn main() {
    let pebble = get_input();
    let weight_difference = get_difference(&pebble);
    let num = get_n_of_weight(&weight_difference);
    println!("{}", num);
}

fn get_input() -> Vec<u32> {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace();
    let mut get = || iter.next().unwrap();

    let n = str::parse::<usize>(get()).unwrap();
    let mut pebble: Vec<u32> = vec![0; n];

    for p in pebble.iter_mut() {
        let w = str::parse::<u32>(get()).unwrap();
        *p = w;
    }

    pebble
}

fn get_difference(pebble: &[u32]) -> u32 {
    let mut w: u32 = 0;

    for p in pebble.iter() {
        w = match w > *p {
            true => w - *p,
            false => *p - w,
        };
    }

    w
}

fn get_n_of_weight(weight_difference: &u32) -> u32 {
    let weights: [u32; 7] = [1, 2, 5, 10, 20, 50, 100];
    let mut remain: u32 = weight_difference.clone();
    let mut num: u32 = 0;

    for w in weights.iter().rev() {
        num += remain / w;
        remain %= w;
    }

    num
}
