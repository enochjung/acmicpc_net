use std::fmt::Write;

const MAX_VAL: usize = 100000;

fn main() {
    let (arr, queries) = get_input();

    let mut output = String::new();
    let answer = get_answer(arr, queries);
    answer.into_iter().for_each(|x| {
        writeln!(output, "{}", x).unwrap();
    });
    print!("{}", output);
}

fn get_input() -> (Vec<u32>, Vec<(u32, u32)>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let arr = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<u32>)
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

            (get() - 1, get())
        })
        .collect();

    (arr, queries)
}

fn get_answer(arr: Vec<u32>, queries: Vec<(u32, u32)>) -> Vec<u32> {
    let mut answer = vec![0; queries.len()];

    let mut indexed_queries: Vec<_> = queries.into_iter().enumerate().collect();
    indexed_queries.sort_by(|(_, (a_start, _)), (_, (b_start, _))| a_start.cmp(&b_start));

    let mut solver = solver::Solver::new(arr);

    let mut removed_idx = 0;
    indexed_queries
        .into_iter()
        .for_each(|(query_idx, (start, end))| {
            let start = start as usize;
            let end = end as usize;

            while removed_idx < start {
                solver.increase_start_pointer(start - removed_idx);
                removed_idx = start;
            }

            let freq = solver.get_max_frequent_count(end);
            answer[query_idx] = freq;
        });

    answer
}

mod solver {
    use crate::MAX_VAL;
    use std::cell::RefCell;
    use std::cmp::Ordering;
    use std::collections::{BinaryHeap, HashSet};

    pub struct Solver {
        start_idx: usize,
        arr: Vec<u32>,
        removed_value_counter: Vec<u32>,
        tree: Vec<TreeElement>,
    }

    impl Solver {
        pub fn new(arr: Vec<u32>) -> Self {
            let mut val_to_cnt = vec![0; MAX_VAL + 1];
            let mut count = vec![0; arr.len()];

            for i in 0..arr.len() {
                let value = arr[i];
                val_to_cnt[value as usize] += 1;
                count[i] = val_to_cnt[value as usize];
            }

            let mut tree = vec![TreeElement::new(); arr.len() + 1];
            for i in (0..arr.len()).rev() {
                let value = arr[i];
                let count = count[i];

                let mut idx = i + 1;
                while idx <= arr.len() {
                    if tree[idx].set.contains(&value) == false {
                        tree[idx].set.insert(value);
                        tree[idx].heap.borrow_mut().push(Element {
                            value,
                            count,
                            removed_latest: 0,
                        });
                    }
                    idx += idx & (!idx + 1);
                }
            }

            val_to_cnt.clear();
            val_to_cnt.resize(MAX_VAL + 1, 0);

            Solver {
                start_idx: 0,
                arr,
                removed_value_counter: val_to_cnt,
                tree,
            }
        }

        pub fn get_max_frequent_count(&self, end_idx: usize) -> u32 {
            let mut result = 0;

            let mut idx = end_idx;
            while idx > 0 {
                let mut heap = self.tree[idx].heap.borrow_mut();
                loop {
                    if heap.is_empty() {
                        break;
                    }
                    let top = heap.peek().unwrap();
                    let value = top.value;
                    let count = top.count;
                    let removed_prev = top.removed_latest;
                    let removed_latest = self.removed_value_counter[top.value as usize];
                    if removed_prev == removed_latest {
                        break;
                    }

                    heap.pop();
                    if count > removed_latest {
                        let elem = Element {
                            value: value,
                            count: count,
                            removed_latest,
                        };
                        heap.push(elem);
                    }
                }

                if heap.is_empty() == false {
                    let top = heap.peek().unwrap();
                    let remain_count = top.count - top.removed_latest;
                    result = result.max(remain_count);
                }
                idx -= idx & (!idx + 1);
            }

            result
        }

        pub fn increase_start_pointer(&mut self, size: usize) -> () {
            for i in self.start_idx..self.start_idx + size {
                let value = self.arr[i];
                self.removed_value_counter[value as usize] += 1;
            }

            self.start_idx += size;
        }
    }

    #[derive(Clone)]
    struct TreeElement {
        heap: RefCell<BinaryHeap<Element>>,
        set: HashSet<u32>,
    }

    impl TreeElement {
        fn new() -> Self {
            TreeElement {
                heap: RefCell::new(BinaryHeap::new()),
                set: HashSet::new(),
            }
        }
    }

    #[derive(Clone, Eq, PartialEq)]
    struct Element {
        value: u32,
        count: u32,
        removed_latest: u32,
    }

    impl Ord for Element {
        fn cmp(&self, other: &Self) -> Ordering {
            let self_diff = self.count - self.removed_latest;
            let other_diff = other.count - other.removed_latest;

            self_diff
                .cmp(&other_diff)
                .then(self.value.cmp(&other.value))
                .then(self.count.cmp(&other.count))
                .then(self.removed_latest.cmp(&other.removed_latest))
        }
    }

    impl PartialOrd for Element {
        fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
            Some(self.cmp(other))
        }
    }
}
