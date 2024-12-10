fn main() {
    let (candies, relation, k) = get_input();
    let groups = build_groups(candies, relation);

    let answer = get_answer(groups, k);
    println!("{}", answer);
}

struct Group {
    num_candies: u32,
    num_people: usize,
}

impl std::ops::AddAssign for Group {
    fn add_assign(&mut self, other: Self) {
        *self = Self {
            num_candies: self.num_candies + other.num_candies,
            num_people: self.num_people + other.num_people,
        };
    }
}

fn get_input() -> (Vec<u32>, Vec<(usize, usize)>, usize) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let (_, m, k) = (get(), get(), get());

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let candies = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<u32>)
        .collect();

    let mut input = String::new();
    for _ in 0..m {
        std::io::stdin().read_line(&mut input).unwrap();
    }
    let groups = input
        .lines()
        .map(|line| {
            let mut iter = line.split_ascii_whitespace().flat_map(str::parse::<usize>);
            let mut get = || iter.next().unwrap();

            let (a, b) = (get() - 1, get() - 1);
            (a, b)
        })
        .collect();

    (candies, groups, k)
}

fn build_groups(candies: Vec<u32>, relation: Vec<(usize, usize)>) -> Vec<Group> {
    let mut groups = Vec::new();

    let n = candies.len();
    let mut edges = vec![Vec::new(); n];
    relation.into_iter().for_each(|(a, b)| {
        edges[a].push(b);
        edges[b].push(a);
    });

    let mut visited = vec![false; n];
    for i in 0..n {
        if visited[i] == false {
            let res = visit(i, &edges, &candies, &mut visited);
            groups.push(res);
        }
    }

    groups
}

fn visit(
    idx: usize,
    edges: &Vec<Vec<usize>>,
    candies: &Vec<u32>,
    visited: &mut Vec<bool>,
) -> Group {
    visited[idx] = true;

    let mut my_group = Group {
        num_candies: candies[idx],
        num_people: 1,
    };

    for to in edges[idx].iter() {
        if visited[*to] == false {
            let res = visit(*to, edges, candies, visited);
            my_group += res;
        }
    }

    my_group
}

fn get_answer(groups: Vec<Group>, k: usize) -> u32 {
    let n = groups.len();
    let mut d = vec![vec![0; k]; 2];

    for i in 0..n {
        let (left, right) = d.split_at_mut(1);
        let dst;
        let src;
        if i & 1 == 0 {
            dst = &mut left[0];
            src = &right[0];
        } else {
            dst = &mut right[0];
            src = &left[0];
        }

        let group = &groups[i];

        for j in 1..k {
            let prev = dst[j - 1].max(src[j]);
            let new = if group.num_people <= j {
                src[j - group.num_people] + group.num_candies
            } else {
                0
            };
            dst[j] = prev.max(new);
        }
    }

    d[1 - (n & 1)][k - 1]
}
