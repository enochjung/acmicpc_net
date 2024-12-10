use std::fmt::Write;

fn main() {
    let (arr, queries) = get_input();
    let answer = get_answer(arr, queries);

    let mut output = String::new();
    answer
        .into_iter()
        .for_each(|x| writeln!(output, "{}", x).unwrap());
    print!("{}", output);
}

enum Query {
    Update(UpdateQuery),
    Print(PrintQuery),
}

struct UpdateQuery {
    idx: usize,
    val: i64,
}

struct PrintQuery {
    time: usize,
    start: usize,
    end: usize,
}

fn get_input() -> (Vec<i64>, Vec<Query>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let arr = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<i64>)
        .collect();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let q = input.trim().parse::<usize>().unwrap();

    let mut queries = Vec::with_capacity(q);
    for _ in 0..q {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<i64>);
        let mut get = || iter.next().unwrap();

        let query_type = get();
        match query_type {
            1 => {
                let idx = (get() - 1) as usize;
                let val = get();
                queries.push(Query::Update(UpdateQuery { idx, val }));
            }
            _ => {
                let time = get() as usize;
                let start = (get() - 1) as usize;
                let end = (get()) as usize;
                queries.push(Query::Print(PrintQuery { time, start, end }));
            }
        }
    }

    (arr, queries)
}

fn get_answer(arr: Vec<i64>, queries: Vec<Query>) -> Vec<i64> {
    let mut tree = binary_indexed_tree::BIT::new(arr);
    let (update_queries, print_queries) = divide_queries(&queries);

    let mut print_queries: Vec<_> = print_queries.into_iter().enumerate().collect();
    print_queries.sort_by(|a, b| a.1.time.cmp(&b.1.time));

    let mut answer = vec![0; print_queries.len()];

    let mut time = 0;
    print_queries.into_iter().for_each(|(pq_idx, pq)| {
        while time < pq.time {
            let uq = update_queries[time];
            tree.update(uq.idx, uq.val);
            time += 1;
        }
        let sum = tree.get_sum(pq.start, pq.end);
        answer[pq_idx] = sum;
    });

    answer
}

fn divide_queries(queries: &Vec<Query>) -> (Vec<&UpdateQuery>, Vec<&PrintQuery>) {
    let update_queries = queries
        .iter()
        .flat_map(|x| match x {
            Query::Update(uq) => Some(uq),
            _ => None,
        })
        .collect();
    let print_queries = queries
        .into_iter()
        .flat_map(|x| match x {
            Query::Print(pq) => Some(pq),
            _ => None,
        })
        .collect();

    (update_queries, print_queries)
}

mod binary_indexed_tree {
    pub struct BIT {
        table: Vec<i64>,
    }

    impl BIT {
        pub fn new(arr: Vec<i64>) -> Self {
            let table = vec![0; arr.len() + 1];

            let mut tree = BIT { table };

            for i in 0..arr.len() {
                let idx = i;
                let val = arr[i];
                tree.add(idx, val);
            }

            tree
        }

        pub fn update(&mut self, idx: usize, val: i64) -> () {
            let prev_val = self.get_sum_until(idx + 1) - self.get_sum_until(idx);
            let diff = val - prev_val;
            self.add(idx, diff);
        }

        pub fn get_sum(&self, start: usize, end: usize) -> i64 {
            let until_end = self.get_sum_until(end);
            let until_start = self.get_sum_until(start);
            until_end - until_start
        }

        fn add(&mut self, idx: usize, val: i64) -> () {
            let mut idx = idx + 1;

            while idx < self.table.len() {
                self.table[idx] += val;
                idx += idx & (!idx + 1);
            }
        }

        fn get_sum_until(&self, end: usize) -> i64 {
            let mut idx = end;
            let mut sum = 0;

            while idx > 0 {
                sum += self.table[idx];
                idx -= idx & (!idx + 1);
            }

            sum
        }
    }
}
