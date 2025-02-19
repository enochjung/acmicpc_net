const MAX_Y: usize = 100000;

fn main() {
    let tc = get_tc_input();

    for _ in 0..tc {
        let (eggs, parades) = get_input();
        let answer = get_answer(eggs, parades);
        println!("{}", answer);
    }
}

fn get_tc_input() -> usize {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let tc = input.trim().parse::<usize>().unwrap();
    tc
}

fn get_input() -> (Vec<Point>, Vec<Area>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let (n, m) = (get(), get());

    let eggs = (0..n)
        .map(|_| {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<u32>);
            let mut get = || iter.next().unwrap();
            let (x, y) = (get(), get());
            Point { x, y }
        })
        .collect();

    let parades = (0..m)
        .map(|_| {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<u32>);
            let mut get = || iter.next().unwrap();
            let (x0, x1, y0, y1) = (get(), get() + 1, get(), get() + 1);
            Area { x0, x1, y0, y1 }
        })
        .collect();

    (eggs, parades)
}

fn get_answer(eggs: Vec<Point>, parades: Vec<Area>) -> u64 {
    let mut answer = 0;

    let mut queries = generate_queries(eggs, parades);
    queries.sort();

    let mut tree = BinaryIndexedTree::new(MAX_Y + 1);
    queries
        .into_iter()
        .for_each(|Query { x: _, query_type }| match query_type {
            QueryType::Egg { y } => {
                let count = tree.get(y as usize);
                answer += count as u64;
            }
            QueryType::ParadeStart { y0, y1 } => {
                tree.add(y0 as usize, y1 as usize, 1);
            }
            QueryType::ParadeEnd { y0, y1 } => {
                tree.add(y0 as usize, y1 as usize, -1);
            }
        });

    answer
}

fn generate_queries(eggs: Vec<Point>, parades: Vec<Area>) -> Vec<Query> {
    let queries = eggs
        .into_iter()
        .map(|Point { x, y }| {
            let query_type = QueryType::Egg { y };
            Query { x, query_type }
        })
        .chain(parades.into_iter().flat_map(|Area { x0, x1, y0, y1 }| {
            let type_start = QueryType::ParadeStart { y0, y1 };
            let type_end = QueryType::ParadeEnd { y0, y1 };
            let query_start = Query {
                x: x0,
                query_type: type_start,
            };
            let query_end = Query {
                x: x1,
                query_type: type_end,
            };
            [query_start, query_end]
        }))
        .collect::<Vec<_>>();

    queries
}

struct Point {
    x: u32,
    y: u32,
}

struct Area {
    x0: u32,
    x1: u32,
    y0: u32,
    y1: u32,
}

#[derive(PartialEq, Eq)]
struct Query {
    x: u32,
    query_type: QueryType,
}

impl Ord for Query {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.x
            .cmp(&other.x)
            .then(self.query_type.cmp(&other.query_type))
    }
}

impl PartialOrd for Query {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(&other))
    }
}

#[derive(PartialEq, Eq)]
enum QueryType {
    Egg { y: u32 },
    ParadeStart { y0: u32, y1: u32 },
    ParadeEnd { y0: u32, y1: u32 },
}

impl Ord for QueryType {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        let self_priority = match self {
            QueryType::Egg { y: _ } => 1,
            _ => 0,
        };
        let other_priority = match other {
            QueryType::Egg { y: _ } => 1,
            _ => 0,
        };
        self_priority.cmp(&other_priority)
    }
}

impl PartialOrd for QueryType {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(&other))
    }
}

struct BinaryIndexedTree {
    tree: Vec<i32>,
}

impl BinaryIndexedTree {
    fn new(n: usize) -> Self {
        let tree = vec![0; n + 1];
        BinaryIndexedTree { tree }
    }

    fn add(&mut self, start: usize, end: usize, value: i32) -> () {
        self.add_until(end, value);
        self.add_until(start, -value);
    }

    fn add_until(&mut self, end: usize, value: i32) -> () {
        let mut idx = end;

        while idx > 0 {
            self.tree[idx] += value;
            idx -= idx & (!idx + 1);
        }
    }

    fn get(&self, idx: usize) -> u32 {
        let mut idx = idx + 1;
        let mut sum = 0;

        while idx < self.tree.len() {
            sum += self.tree[idx];
            idx += idx & (!idx + 1);
        }

        sum as u32
    }
}
