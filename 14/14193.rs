fn main() {
    let villages: Vec<Village> = get_input();

    for village in villages {
        println!("{}", if can_be_conquered(&village) { 'Y' } else { 'N' });
    }
}

fn can_be_conquered(v: &Village) -> bool {
    scc::is_one_scc(&v.edge) && gcd_of_path_len(&v.edge) == 1
}

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn gcd_of_path_len(edge: &Vec<Vec<usize>>) -> usize {
    let n = edge.len();
    let mut arrival_time: Vec<Option<usize>> = vec![None; n];

    fn dfs(
        x: usize,
        current_time: usize,
        edge: &Vec<Vec<usize>>,
        arrival_time: &mut Vec<Option<usize>>,
    ) -> usize {
        if arrival_time[x] != None {
            return current_time.abs_diff(arrival_time[x].unwrap());
        }

        arrival_time[x] = Some(current_time);

        let mut gcd_time: Option<usize> = None;

        for to in edge[x].iter() {
            let to = *to;
            let ret = dfs(to, current_time + 1, edge, arrival_time);
            gcd_time = if gcd_time == None {
                Some(ret)
            } else {
                Some(gcd(ret, gcd_time.unwrap()))
            }
        }

        gcd_time.unwrap()
    }

    dfs(0, 0, edge, &mut arrival_time)
}

struct Village {
    edge: Vec<Vec<usize>>,
}

impl Village {
    fn new(n: usize) -> Village {
        Village {
            edge: vec![Vec::new(); n],
        }
    }

    fn add_edge(&mut self, from: usize, to: usize) -> () {
        self.edge[from].push(to);
    }
}

mod scc {
    pub fn is_one_scc(edge: &Vec<Vec<usize>>) -> bool {
        let n = edge.len();
        let mut dfsn: Vec<usize> = vec![0; n];
        let mut count: usize = 0;
        dfs(0, edge, &mut dfsn, &mut count) != None && count == n
    }

    fn dfs(
        x: usize,
        edge: &Vec<Vec<usize>>,
        dfsn: &mut Vec<usize>,
        count: &mut usize,
    ) -> Option<usize> {
        *count += 1;
        dfsn[x] = *count;

        let mut top: usize = dfsn[x];
        for to in edge[x].iter() {
            if dfsn[*to] == 0 {
                let ret = dfs(*to, edge, dfsn, count);
                if ret == None {
                    return None;
                }
                top = std::cmp::min(top, ret.unwrap());
            } else {
                top = std::cmp::min(top, dfsn[*to]);
            }
        }

        if top == dfsn[x] && top != 1 {
            return None;
        }

        Some(top)
    }
}

fn get_input() -> Vec<Village> {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let mut villages: Vec<Village> = Vec::new();

    loop {
        let (n, m) = (get(), get());
        if n == 0 {
            break;
        }

        let mut village = Village::new(n);

        for _ in 0..m {
            let (from, to) = (get() - 1, get() - 1);
            village.add_edge(from, to);
        }

        villages.push(village);
    }

    villages
}
