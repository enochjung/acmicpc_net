fn main() {
    let input = get_input();
    let k = input.0;
    let mut scores = input.1;

    scores.sort_by(|a, b| b.cmp(a));

    println!("{}", scores[k - 1]);
}

fn get_input() -> (usize, Vec<u32>) {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let n = get();
    let k = get();

    let mut scores: Vec<u32> = vec![0; n];

    for i in 0..n {
        scores[i] = u32::try_from(get()).unwrap();
    }

    (k, scores)
}
