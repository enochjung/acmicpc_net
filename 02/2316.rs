fn main() {
    let (n, edges) = get_input();
    let answer = get_answer(n, edges);
    println!("{}", answer);
}

fn get_input() -> (usize, Vec<(usize, usize)>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();
    let (n, m) = (get(), get());

    let edges = (0..m)
        .map(|_| {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
            let mut get = || iter.next().unwrap();

            (get() - 1, get() - 1)
        })
        .collect();

    (n, edges)
}

fn get_answer(n: usize, edges: Vec<(usize, usize)>) -> u32 {
    let mut model = mcmf::MCMF::new(n * 2 - 2, 0, 1);

    let get_entrance = |idx| match idx {
        0 => None,
        1 => Some(1),
        x => Some(x),
    };
    let get_exit = |idx| match idx {
        0 => Some(0),
        1 => None,
        x => Some(x + n - 2),
    };

    edges.into_iter().for_each(|(a, b)| {
        let a_entrance = get_entrance(a);
        let a_exit = get_exit(a);
        let b_entrance = get_entrance(b);
        let b_exit = get_exit(b);

        if let (Some(from), Some(to)) = (a_exit, b_entrance) {
            model.add_edge(from, to, 1, 0);
        }
        if let (Some(from), Some(to)) = (b_exit, a_entrance) {
            model.add_edge(from, to, 1, 0);
        }
    });
    (2..n).for_each(|idx| {
        let entrance = get_entrance(idx).unwrap();
        let exit = get_exit(idx).unwrap();
        model.add_edge(entrance, exit, 1, 0);
    });

    model.get_flow()
}

mod mcmf {
    pub struct MCMF {
        n: usize,
        src: usize,
        sink: usize,
        edges: Vec<Vec<Edge>>,
    }

    impl MCMF {
        pub fn new(n: usize, src: usize, sink: usize) -> Self {
            let edges = vec![Vec::new(); n];

            MCMF {
                n,
                src,
                sink,
                edges,
            }
        }

        pub fn add_edge(&mut self, from: usize, to: usize, capacity: u32, cost: i32) -> () {
            let rev_idx_for_from = self.edges[to].len();
            let rev_idx_for_to = self.edges[from].len();

            self.edges[from].push(Edge::new(to, capacity, cost, rev_idx_for_from));
            self.edges[to].push(Edge::new(from, 0, -cost, rev_idx_for_to));
        }

        fn spfa(
            &self,
            trace: &mut Vec<(i32, i32)>,
            dp: &mut Vec<i32>,
            in_queue: &mut Vec<bool>,
        ) -> () {
            let mut deque = std::collections::VecDeque::new();

            dp[self.src] = 0;
            deque.push_back(self.src);
            in_queue[self.src] = true;

            while let Some(idx) = deque.pop_front() {
                in_queue[idx] = false;

                for edge_idx in 0..self.edges[idx].len() {
                    let target_edge = &self.edges[idx][edge_idx];

                    if target_edge.capacity > 0 && dp[target_edge.to] > dp[idx] + target_edge.cost {
                        dp[target_edge.to] = dp[idx] + target_edge.cost;
                        trace[target_edge.to] = (idx as i32, edge_idx as i32);

                        if in_queue[target_edge.to] == false {
                            deque.push_back(target_edge.to);
                            in_queue[target_edge.to] = true;
                        }
                    }
                }
            }
        }

        pub fn get_flow(mut self) -> u32 {
            let mut sum_flow = 0;

            let mut trace = Vec::new();
            let mut dp = Vec::new();
            let mut in_queue = Vec::new();

            loop {
                trace.clear();
                trace.resize(self.n, (-1, -1));

                dp.clear();
                dp.resize(self.n, i32::MAX);

                in_queue.clear();
                in_queue.resize(self.n, false);

                self.spfa(&mut trace, &mut dp, &mut in_queue);

                if trace[self.sink].0 == -1 {
                    break;
                }

                let mut flow = u32::MAX;

                let mut idx = self.sink;
                while idx != self.src {
                    flow =
                        flow.min(self.edges[trace[idx].0 as usize][trace[idx].1 as usize].capacity);
                    idx = trace[idx].0 as usize;
                }

                let mut idx = self.sink;
                while idx != self.src {
                    let edge = &self.edges[trace[idx].0 as usize][trace[idx].1 as usize];
                    let edge_rev_idx = edge.rev_idx;

                    self.edges[trace[idx].0 as usize][trace[idx].1 as usize].capacity -= flow;
                    self.edges[idx][edge_rev_idx].capacity += flow;

                    idx = trace[idx].0 as usize;
                }

                sum_flow += flow;
            }

            sum_flow
        }
    }

    #[derive(Clone)]
    struct Edge {
        to: usize,
        capacity: u32,
        cost: i32,
        rev_idx: usize,
    }

    impl Edge {
        fn new(to: usize, capacity: u32, cost: i32, rev_idx: usize) -> Self {
            Edge {
                to,
                capacity,
                cost,
                rev_idx,
            }
        }
    }
}
