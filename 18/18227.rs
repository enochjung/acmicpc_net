use std::fmt::Write;

fn main() {
    let (n, root, edges, queries) = get_input();
    let tree = Tree::new(n, root, edges);
    let answer = get_answer(tree, queries);

    let mut output = String::new();
    answer.into_iter().for_each(|x| {
        writeln!(output, "{}", x).unwrap();
    });
    print!("{}", output);
}

fn get_input() -> (usize, usize, Vec<(usize, usize)>, Vec<Query>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let (n, root) = (get(), get() - 1);

    let edges = (0..n - 1)
        .map(|_| {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
            let mut get = || iter.next().unwrap();

            (get() - 1, get() - 1)
        })
        .collect();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let q = input.trim().parse::<usize>().unwrap();

    let queries = (0..q)
        .map(|_| {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
            let mut get = || iter.next().unwrap();

            let query_type = get();
            let idx = get() - 1;
            match query_type {
                1 => Query::Fill { idx },
                _ => Query::Print { idx },
            }
        })
        .collect();

    (n, root, edges, queries)
}

fn get_answer(tree: Tree, queries: Vec<Query>) -> Vec<i64> {
    let n = tree.n;
    let (depths, index_table) = reform_tree(tree);
    let mut bit = BinaryIndexedTree::new(n);
    let mut result = Vec::new();

    queries.into_iter().for_each(|query| match query {
        Query::Fill { idx } => {
            let idx = index_table[idx].0;
            bit.add(idx, 1);
        }
        Query::Print { idx } => {
            let (start, end) = index_table[idx];
            let sum = bit.get_sum(start, end) as i64;
            let total_water = sum * (depths[start] as i64 + 1);
            result.push(total_water);
        }
    });

    result
}

fn reform_tree(tree: Tree) -> (Vec<u32>, Vec<(usize, usize)>) {
    let mut depths = vec![0; tree.n];
    let mut index_table = vec![(0, 0); tree.n];
    let mut visited = vec![false; tree.n];

    travel(
        tree.root,
        0,
        &tree.edges,
        0,
        &mut visited,
        &mut depths,
        &mut index_table,
    );

    (depths, index_table)
}

fn travel(
    idx: usize,
    reformed_idx: usize,
    edges: &Vec<Vec<usize>>,
    level: u32,
    visited: &mut Vec<bool>,
    depths: &mut Vec<u32>,
    index_table: &mut Vec<(usize, usize)>,
) -> usize {
    visited[idx] = true;
    depths[reformed_idx] = level;
    index_table[idx].0 = reformed_idx;

    let mut reformed_idx = reformed_idx + 1;
    for to in edges[idx].iter() {
        if visited[*to] == false {
            reformed_idx = travel(
                *to,
                reformed_idx,
                edges,
                level + 1,
                visited,
                depths,
                index_table,
            );
        }
    }

    index_table[idx].1 = reformed_idx;
    reformed_idx
}

struct Tree {
    n: usize,
    root: usize,
    edges: Vec<Vec<usize>>,
}

impl Tree {
    fn new(n: usize, root: usize, edges: Vec<(usize, usize)>) -> Self {
        let mut new_edges = vec![Vec::new(); n];
        edges.into_iter().for_each(|(a, b)| {
            new_edges[a].push(b);
            new_edges[b].push(a);
        });

        Tree {
            n,
            root,
            edges: new_edges,
        }
    }
}

enum Query {
    Fill { idx: usize },
    Print { idx: usize },
}

struct BinaryIndexedTree {
    table: Vec<i32>,
}

impl BinaryIndexedTree {
    fn new(n: usize) -> Self {
        BinaryIndexedTree {
            table: vec![0; n + 1],
        }
    }

    fn add(&mut self, idx: usize, val: i32) -> () {
        let mut idx = idx + 1;

        while idx < self.table.len() {
            self.table[idx] += val;
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
            sum += self.table[idx];
            idx -= idx & (!idx + 1);
        }

        sum
    }
}
