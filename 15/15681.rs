use std::fmt::Write;

fn main() {
    let (n, root, edges, queries) = get_input();

    let mut builder = TreeBuilder::new(n);
    for edge in edges.into_iter() {
        builder.add_edge(edge.0, edge.1);
    }
    let tree = builder.build(root);

    let mut output = String::new();
    for x in queries.into_iter() {
        let num = tree.get_n_of_subtree_nodes(x);
        writeln!(output, "{}", num).unwrap();
    }
    print!("{}", output);
}

struct TreeBuilder {
    n: usize,
    edges: Vec<Vec<usize>>,
}

impl TreeBuilder {
    fn new(n: usize) -> Self {
        let edges = vec![Vec::new(); n];

        TreeBuilder { n, edges }
    }

    fn add_edge(&mut self, a: usize, b: usize) -> () {
        self.edges[a].push(b);
        self.edges[b].push(a);
    }

    fn build(self, root: usize) -> Tree {
        let mut counts = vec![0; self.n];

        self.travel(root, &mut counts);

        Tree { counts }
    }

    fn travel(&self, idx: usize, counts: &mut Vec<usize>) -> usize {
        counts[idx] = 1;

        for to in self.edges[idx].iter() {
            if counts[*to] == 0 {
                counts[idx] += self.travel(*to, counts);
            }
        }

        counts[idx]
    }
}

struct Tree {
    counts: Vec<usize>,
}

impl Tree {
    fn get_n_of_subtree_nodes(&self, idx: usize) -> usize {
        self.counts[idx]
    }
}

fn get_input() -> (usize, usize, Vec<(usize, usize)>, Vec<usize>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let (n, root, q) = (get(), get() - 1, get());

    let mut input = String::new();
    for _ in 0..n - 1 {
        std::io::stdin().read_line(&mut input).unwrap();
    }

    let edges = input
        .lines()
        .map(|line| {
            let mut iter = line.split_ascii_whitespace().flat_map(str::parse::<usize>);
            let mut get = || iter.next().unwrap();

            (get() - 1, get() - 1)
        })
        .collect();

    let mut input = String::new();
    for _ in 0..q {
        std::io::stdin().read_line(&mut input).unwrap();
    }
    let queries = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<usize>)
        .map(|x| x - 1)
        .collect();

    (n, root, edges, queries)
}
