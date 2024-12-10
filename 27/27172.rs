use std::fmt::Write;

const M: usize = 1000000;

fn main() {
    let arr = get_input();
    let ans = get_answer(&arr);

    let mut output = String::new();
    for x in ans.into_iter() {
        write!(output, "{} ", x).unwrap();
    }
    println!("{}", output);
}

fn get_input() -> Vec<i32> {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input
        .split_ascii_whitespace()
        .flat_map(str::parse::<i32>)
        .collect()
}

fn get_answer(arr: &Vec<i32>) -> Vec<i32> {
    let mut score = vec![0; arr.len()];

    let table = build_index_table(arr.iter());
    for (me_idx, me_val) in arr.iter().enumerate() {
        let me_val = *me_val as usize;
        let mut other_val = me_val * 2;

        while other_val <= M {
            if table[other_val].is_some() {
                let other_idx = table[other_val].unwrap();
                score[me_idx] += 1;
                score[other_idx] -= 1;
            }
            other_val += me_val;
        }
    }

    score
}

fn build_index_table<'a>(arr: impl Iterator<Item = &'a i32>) -> Vec<Option<usize>> {
    let mut table = vec![None; M + 1];

    arr.enumerate().for_each(|(idx, val)| {
        table[*val as usize] = Some(idx);
    });

    table
}
