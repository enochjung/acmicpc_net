const MAX_N: usize = 100;

fn main() {
    let (n, connectivity) = get_input();
    let answer = get_answer(n, connectivity);

    println!("{}", answer + 1);
}

fn get_input() -> (usize, Vec<(usize, usize)>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let (n, m) = (get(), get());
    let mut connectivity = vec![(0, 0); m];

    for i in 0..m {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace().flat_map(str::parse::<usize>);
        let mut get = || iter.next().unwrap();

        connectivity[i] = (get() - 1, get() - 1);
    }

    (n, connectivity)
}

fn get_answer(n: usize, connectivity: Vec<(usize, usize)>) -> usize {
    let mut path = [MAX_N; MAX_N * MAX_N];

    let idx = |x, y| x * n + y;

    for i in 0..n {
        path[idx(i, i)] = 0;
    }
    for (a, b) in connectivity {
        path[idx(a, b)] = 1;
        path[idx(b, a)] = 1;
    }
    for k in 0..n {
        for i in 0..n {
            for j in 0..n {
                let new_path = path[idx(i, k)] + path[idx(k, j)];
                path[idx(i, j)] = path[idx(i, j)].min(new_path);
            }
        }
    }

    let min_elem = (0..n)
        .map(|x| &path[x * n..(x + 1) * n])
        .map(|s| s.iter().sum::<usize>())
        .enumerate()
        .min_by(|lhs, rhs| lhs.1.cmp(&rhs.1).then(lhs.0.cmp(&rhs.0)));

    min_elem.unwrap().0
}
