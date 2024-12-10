fn main() {
    let rates = get_input();
    let difficulty = get_difficulty(rates);

    println!("{difficulty}");
}

fn get_difficulty(rates: Vec<u32>) -> u32 {
    let len: usize = rates.len();

    match len {
        ..=0 => 0,
        _ => {
            let n_cut = (len * 15 + 50) / 100;
            let valid_rates = &rates[n_cut..len - n_cut];

            let sum: u32 = valid_rates.iter().sum();
            let len = u32::try_from(valid_rates.len()).unwrap();
            let avg = (sum + len / 2) / len;

            avg
        }
    }
}

fn get_input() -> Vec<u32> {
    let mut line: String = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let n: usize = line.trim().parse::<usize>().unwrap();

    let mut rates: Vec<u32> = vec![0; n];

    for i in 0..n {
        line.clear();
        std::io::stdin().read_line(&mut line).unwrap();
        let rate: u32 = line.trim().parse::<u32>().unwrap();

        rates[i] = rate;
    }

    rates.sort();

    rates
}
