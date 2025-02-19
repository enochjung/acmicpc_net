use std::fmt::Write;

fn main() {
    let (n, edges, queries) = get_input();

    let tree = Tree::new(n, edges);

    let mut output = String::new();
    queries.into_iter().for_each(|(a, b, c)| {
        let result = get_circumcenter(&tree, a as usize, b as usize, c as usize);
        if result.is_none() {
            writeln!(output, "-1").unwrap();
        } else {
            writeln!(output, "{}", result.unwrap() + 1).unwrap();
        }
    });
    print!("{}", output);
}

fn get_input() -> (usize, Vec<(u32, u32)>, Vec<(u32, u32, u32)>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<usize>().unwrap();

    let edges = (1..n)
        .map(|_| {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<u32>);
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
            let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<u32>);
            let mut get = || iter.next().unwrap();

            (get() - 1, get() - 1, get() - 1)
        })
        .collect();

    (n, edges, queries)
}

fn get_circumcenter(tree: &Tree, a: usize, b: usize, c: usize) -> Option<usize> {
    let point_ab = get_midpoint(tree, a, b);
    let point_bc = get_midpoint(tree, b, c);
    let point_ca = get_midpoint(tree, c, a);

    if point_ab.is_none() || point_bc.is_none() || point_ca.is_none() {
        None
    } else if point_ab == point_bc {
        point_ab
    } else if point_bc == point_ca {
        point_bc
    } else if point_ca == point_ab {
        point_ca
    } else {
        None
    }
}

fn get_midpoint(tree: &Tree, a: usize, b: usize) -> Option<usize> {
    let dist = tree.get_distance(a, b);

    if dist & 1 != 0 {
        return None;
    }

    let half_dist = dist / 2;
    let depth_a = tree.get_depth(a);
    let depth_b = tree.get_depth(b);

    Some(tree.get_ancestor(if depth_a > depth_b { a } else { b }, half_dist))
}

struct Tree {
    log_n: usize,
    depths: Vec<u32>,
    ancestor_table: Vec<u32>,
}

impl Tree {
    fn new(n: usize, edges: Vec<(u32, u32)>) -> Self {
        let log_n = (n - 1).ilog2() as usize + 1;
        let mut depths = vec![u32::MAX; n];
        let mut ancestor_table = vec![0; n * log_n];

        let mut edge_table = vec![Vec::new(); n];
        for (a, b) in edges.into_iter() {
            edge_table[a as usize].push(b);
            edge_table[b as usize].push(a);
        }

        let mut deque = std::collections::VecDeque::new();
        deque.push_back(0);
        depths[0] = 0;
        while !deque.is_empty() {
            let current_node = deque.pop_front().unwrap() as usize;
            let current_depth = depths[current_node];
            for child_node in edge_table[current_node].iter() {
                let child_node = *child_node as usize;
                if depths[child_node] == u32::MAX {
                    deque.push_back(child_node as u32);
                    depths[child_node] = current_depth + 1;
                    ancestor_table[child_node * log_n] = current_node as u32;
                }
            }
        }

        for i in 1..log_n {
            for node in 1..n {
                let parent_node = ancestor_table[node * log_n + i - 1] as usize;
                let parent_parent_node = ancestor_table[parent_node * log_n + i - 1];
                ancestor_table[node * log_n + i] = parent_parent_node;
            }
        }

        Tree {
            log_n,
            depths,
            ancestor_table,
        }
    }

    fn get_distance(&self, a: usize, b: usize) -> u32 {
        let lca = self.get_lowest_common_ancestor(a, b);
        let dist_a = self.depths[a] - self.depths[lca];
        let dist_b = self.depths[b] - self.depths[lca];

        dist_a + dist_b
    }

    fn get_depth(&self, a: usize) -> u32 {
        self.depths[a]
    }

    fn get_ancestor(&self, a: usize, distance: u32) -> usize {
        let mut current_node = a;
        let mut distance = distance;
        let mut idx = 0;

        while distance > 0 {
            if distance & 1 > 0 {
                current_node = self.ancestor_table[current_node * self.log_n + idx] as usize;
            }
            distance >>= 1;
            idx += 1;
        }

        current_node
    }

    fn get_lowest_common_ancestor(&self, a: usize, b: usize) -> usize {
        let (a, b) = if self.depths[a] < self.depths[b] {
            (b, a)
        } else {
            (a, b)
        };
        let a = self.get_ancestor(a, self.depths[a] - self.depths[b]);

        if a == b {
            return a;
        }

        let mut a = a;
        let mut b = b;
        for i in (0..self.log_n).rev() {
            let ancestor_a = self.ancestor_table[a * self.log_n + i] as usize;
            let ancestor_b = self.ancestor_table[b * self.log_n + i] as usize;
            if ancestor_a != ancestor_b {
                a = ancestor_a;
                b = ancestor_b;
            }
        }

        self.ancestor_table[a * self.log_n] as usize
    }
}
