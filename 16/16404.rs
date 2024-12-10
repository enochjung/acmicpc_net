use std::fmt::Write;

fn main() {
    let (tree, queries) = get_input();
    let ic = IndexConverter::new(tree);
    let mut bit = BinaryIndexedTree::new(ic.get_out_size());

    let mut output = String::new();
    queries.into_iter().for_each(|q| match q {
        Query::Update { idx, val } => {
            let (start, end) = ic.get_index(idx);
            bit.segment_add(end, val);
            bit.segment_add(start, -val);
        }
        Query::Print { idx } => {
            let (idx, _) = ic.get_index(idx);
            let val = bit.get(idx);
            writeln!(output, "{}", val).unwrap();
        }
    });
    println!("{}", output);
}

struct Tree {
    size: usize,
    root: usize,
    children: Vec<Vec<usize>>,
}

impl Tree {
    fn new(size: usize, parents: impl Iterator<Item = usize>) -> Self {
        let mut children: Vec<Vec<usize>> = vec![Vec::new(); size];

        parents
            .into_iter()
            .enumerate()
            .for_each(|(idx, parent_idx)| {
                let child_idx = idx + 1;
                children[parent_idx].push(child_idx);
            });

        Tree {
            size,
            root: 0,
            children,
        }
    }
}

struct IndexConverter {
    out_size: usize,
    table: Vec<(usize, usize)>,
}

impl IndexConverter {
    fn new(tree: Tree) -> Self {
        let out_size = 0;
        let table = vec![(0, 0); tree.size];

        let mut ic = IndexConverter { out_size, table };
        ic.visit(tree.root, &tree.children);

        ic
    }

    fn visit(&mut self, idx: usize, children: &Vec<Vec<usize>>) -> () {
        self.table[idx].0 = self.out_size;
        self.out_size += 1;

        children[idx].iter().for_each(|child_idx| {
            self.visit(*child_idx, children);
        });

        self.table[idx].1 = self.out_size;
    }

    fn get_index(&self, idx: usize) -> (usize, usize) {
        self.table[idx]
    }

    fn get_out_size(&self) -> usize {
        self.out_size
    }
}

struct BinaryIndexedTree {
    values: Vec<i64>,
}

impl BinaryIndexedTree {
    fn new(size: usize) -> Self {
        let values = vec![0; size + 1];

        BinaryIndexedTree { values }
    }

    fn get(&self, idx: usize) -> i64 {
        let mut sum = 0;
        let mut idx = idx + 1;
        let len = self.values.len();

        while idx < len {
            sum += self.values[idx as usize];
            idx += idx & (!idx + 1);
        }

        sum
    }

    fn segment_add(&mut self, end: usize, val: i64) -> () {
        let mut idx = end;

        while idx > 0 {
            self.values[idx] += val;
            idx = idx & (idx - 1);
        }
    }
}

enum Query {
    Update { idx: usize, val: i64 },
    Print { idx: usize },
}

fn get_input() -> (Tree, impl Iterator<Item = Query>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let (n, m) = (get(), get());

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let parents = input
        .split_ascii_whitespace()
        .skip(1)
        .flat_map(str::parse::<usize>)
        .map(|x| x - 1);

    let tree = Tree::new(n, parents);

    let queries = (0..m).into_iter().map(|_| {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<i64>);
        let mut get = || iter.next().unwrap();

        let query_type = get();
        match query_type {
            1 => Query::Update {
                idx: (get() - 1) as usize,
                val: get(),
            },
            _ => Query::Print {
                idx: (get() - 1) as usize,
            },
        }
    });

    (tree, queries)
}
