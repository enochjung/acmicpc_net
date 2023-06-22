use std::io;

fn main() {
    let (n_of_basket, queries) = get_input();

    let mut basket: Vec<u32> = vec![0; n_of_basket];

    for query in queries {
        let from: usize = query.0;
        let to: usize = query.1;
        let val: u32 = query.2;
        for i in from..to {
            basket[i] = val;
        }
    }

    for num in basket {
        print!("{num} ");
    }
    println!("");
}

fn get_input() -> (usize, Vec<(usize, usize, u32)>) {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().flat_map(str::parse::<u32>);
    let mut get = || iter.next().unwrap();

    let n = usize::try_from(get()).unwrap();
    let m = usize::try_from(get()).unwrap();
    let mut queries: Vec<(usize, usize, u32)> = vec![(0, 0, 0); m];

    for i in 0..m {
        let from = usize::try_from(get() - 1).unwrap();
        let to = usize::try_from(get()).unwrap();
        let val = get();
        queries[i] = (from, to, val);
    }

    (n, queries)
}
