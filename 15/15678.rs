use std::collections::BinaryHeap;

fn main() {
    let (arr, d) = get_input();
    let ans = get_answer(&arr, d);
    println!("{ans}");
}

fn get_input() -> (Vec<i64>, usize) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let (_, d) = (get(), get());

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let arr = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<i64>)
        .collect();

    (arr, d)
}

fn get_answer(arr: &Vec<i64>, d: usize) -> i64 {
    let mut bh = BinaryHeap::new();
    bh.push((0 as i64, arr.len()));

    let mut answer = i64::MIN;
    for (idx, val) in arr.iter().enumerate() {
        loop {
            let (_, top_idx) = bh.peek().unwrap();
            if *top_idx < idx && idx - *top_idx > d {
                bh.pop();
            } else {
                break;
            }
        }

        let top_val = bh.peek().unwrap().0;
        let new_val = top_val + val;
        bh.push((new_val, idx));

        answer = answer.max(new_val);
    }

    answer
}
