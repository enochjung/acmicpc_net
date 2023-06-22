fn main() {
    let mut wired = get_input();

    wired.sort_by(|a, b| a.0.cmp(&b.0));
    let arr = wired.iter().map(|x| x.1).collect();
    let lis = get_lis(&arr);
    println!("{}", wired.len() - lis);
}

fn get_lis(arr: &Vec<usize>) -> usize {
    let mut buf: Vec<usize> = Vec::new();

    for to in arr {
        let idx = buf.partition_point(|x| x < to);
        if idx == buf.len() {
            buf.push(*to);
        } else {
            buf[idx] = *to;
        }
    }

    buf.len()
}

fn get_input() -> Vec<(usize, usize)> {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let n = get();
    let mut wired: Vec<(usize, usize)> = vec![(0, 0); n];

    for i in 0..n {
        wired[i] = (get() - 1, get() - 1);
    }

    wired
}
