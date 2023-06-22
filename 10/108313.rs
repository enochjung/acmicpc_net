fn main() {
    let (n_of_basket, queries) = get_input();

    let mut basket: Vec<u32> = (1..=u32::try_from(n_of_basket).unwrap()).collect();

    for query in queries {
        let p: usize = query.0;
        let q: usize = query.1;
        let tmp = basket[p];
        basket[p] = basket[q];
        basket[q] = tmp;
    }

    for num in basket {
        print!("{num} ");
    }
    println!("");
}

fn get_input() -> (usize, Vec<(usize, usize)>) {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let n = get();
    let m = get();
    let mut queries: Vec<(usize, usize)> = vec![(0, 0); m];

    for i in 0..m {
        let p = get() - 1;
        let q = get() - 1;
        queries[i] = (p, q);
    }

    (n, queries)
}
