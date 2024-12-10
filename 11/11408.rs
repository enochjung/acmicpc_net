fn main() {
    let (n, m, roles) = get_input();
    let (max_task, min_cost) = get_answer(n, m, roles);
    println!("{}\n{}", max_task, min_cost);
}

struct Role {
    who: usize,
    what: usize,
    how_much: u32,
}

fn get_input() -> (usize, usize, Vec<Role>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();
    let (n, m) = (get(), get());

    let mut roles = Vec::new();
    for i in 0..n {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<u32>);
        let mut get = || iter.next().unwrap();

        let n_roles = get() as usize;
        for _ in 0..n_roles {
            let (task, cost) = ((get() - 1) as usize, get());
            roles.push(Role {
                who: i,
                what: task,
                how_much: cost,
            });
        }
    }

    (n, m, roles)
}

fn get_answer(n: usize, m: usize, roles: Vec<Role>) -> (u32, i32) {
    let mut model = mcmf::MCMF::new(n + m + 2, 0, n + m + 1);
    for i in 0..n {
        model.add_edge(0, i + 1, 1, 0);
    }
    roles.into_iter().for_each(
        |Role {
             who: from,
             what: to,
             how_much: cost,
         }| {
            model.add_edge(from + 1, to + n + 1, 1, cost as i32);
        },
    );
    for i in 0..m {
        model.add_edge(i + n + 1, n + m + 1, 1, 0);
    }

    let result = model.flow();
    (result.flow, result.cost)
}

mod mcmf {
    pub struct Result {
        pub flow: u32,
        pub cost: i32,
    }

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

        pub fn flow(mut self) -> Result {
            let mut sum_flow = 0;
            let mut sum_cost = 0;

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
                    let edge_cost = edge.cost;
                    let edge_rev_idx = edge.rev_idx;

                    sum_cost += flow as i32 * edge_cost;
                    self.edges[trace[idx].0 as usize][trace[idx].1 as usize].capacity -= flow;
                    self.edges[idx][edge_rev_idx].capacity += flow;

                    idx = trace[idx].0 as usize;
                }

                sum_flow += flow;
            }

            Result {
                flow: sum_flow,
                cost: sum_cost,
            }
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
