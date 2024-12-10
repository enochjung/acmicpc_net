use std::fmt::Write;

const MAX_VAL: usize = 1000000;

fn main() {
    let (arr, queries) = get_input();
    let answer = get_answer(arr, queries);

    let mut output = String::new();
    answer.into_iter().for_each(|x| {
        writeln!(output, "{}", x).unwrap();
    });
    print!("{}", output);
}

fn get_input() -> (Vec<i32>, Vec<(u32, u32)>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let arr = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<i32>)
        .collect();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let m = input.trim().parse::<usize>().unwrap();

    let queries = (0..m)
        .map(|_| {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<u32>);
            let mut get = || iter.next().unwrap();

            let start = get() - 1;
            let end = get();
            (start, end)
        })
        .collect();

    (arr, queries)
}

fn get_answer(arr: Vec<i32>, queries: Vec<(u32, u32)>) -> Vec<i32> {
    let mut answer = vec![0; queries.len()];

    let (mut tree, remove_table) = generate_tree_and_table(arr);

    let mut indexed_queries: Vec<_> = queries.into_iter().enumerate().collect();
    indexed_queries.sort_by(|a, b| a.1 .0.cmp(&b.1 .0));

    let mut removed_idx = 0;
    indexed_queries
        .into_iter()
        .for_each(|(query_idx, (start, end))| {
            while removed_idx < start {
                remove_table[removed_idx as usize].iter().for_each(|x| {
                    tree.add(*x as usize, -1);
                });
                removed_idx += 1;
            }

            let n_of_duplicate = tree.get_sum(start as usize, end as usize);
            let n_of_separate = end as i32 - start as i32 - n_of_duplicate;
            answer[query_idx] = n_of_separate;
        });

    answer
}

fn generate_tree_and_table(arr: Vec<i32>) -> (BinaryIndexedTree, Vec<Vec<u32>>) {
    let mut tree = BinaryIndexedTree::new(arr.len());
    let mut remove_table = vec![Vec::new(); arr.len()];

    let mut last_appeared = vec![-1; MAX_VAL + 1];

    for i in 0..arr.len() {
        let val = arr[i] as usize;

        if last_appeared[val] != -1 {
            tree.add(i, 1);
            remove_table[last_appeared[val] as usize].push(i as u32);
        }

        last_appeared[val] = i as i32;
    }

    (tree, remove_table)
}

struct BinaryIndexedTree {
    tree: Vec<i32>,
}

impl BinaryIndexedTree {
    fn new(length: usize) -> Self {
        BinaryIndexedTree {
            tree: vec![0; length + 1],
        }
    }

    fn add(&mut self, idx: usize, val: i32) -> () {
        let mut idx = idx + 1;

        while idx < self.tree.len() {
            self.tree[idx] += val;
            idx += idx & (!idx + 1);
        }
    }

    fn get_sum(&self, start: usize, end: usize) -> i32 {
        self.get_sum_until(end) - self.get_sum_until(start)
    }

    fn get_sum_until(&self, end: usize) -> i32 {
        let mut idx = end;
        let mut sum = 0;

        while idx > 0 {
            sum += self.tree[idx];
            idx -= idx & (!idx + 1);
        }

        sum
    }
}
