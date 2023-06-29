use std::{cmp::Ordering, collections::BinaryHeap};

const MAX_DIST: usize = 9000;

struct Point(i32, i32);
impl Clone for Point {
    fn clone(&self) -> Point {
        Point(self.0, self.1)
    }
}
struct Edge(usize, u32);
impl Clone for Edge {
    fn clone(&self) -> Edge {
        Edge(self.0, self.1)
    }
}

fn main() {
    let points: Vec<Point> = get_input();
    let edges: Vec<Vec<Edge>> = create_edges(&points);
    let min_dist: Option<u32> = get_minimum_distance(0, 1, &edges);
    println!(
        "{}",
        if min_dist != None {
            min_dist.unwrap() as i32
        } else {
            -1
        }
    );
}

fn create_edges(points: &Vec<Point>) -> Vec<Vec<Edge>> {
    let n = points.len();
    let is_prime: Vec<bool> = get_prime_table(MAX_DIST + 1);
    let mut edges: Vec<Vec<Edge>> = vec![Vec::<Edge>::new(); n];

    for i in 0..n - 1 {
        for j in i + 1..n {
            let dx = points[i].0 - points[j].0;
            let dy = points[i].1 - points[j].1;
            let dist = sqrt_u32((dx.pow(2) + dy.pow(2)) as u32);
            if is_prime[dist as usize] {
                edges[i].push(Edge(j, dist));
                edges[j].push(Edge(i, dist));
            }
        }
    }

    edges
}

fn get_prime_table(size: usize) -> Vec<bool> {
    let mut is_prime: Vec<bool> = vec![true; size];
    is_prime[0] = false;
    is_prime[1] = false;

    for i in 2..size {
        if is_prime[i] {
            for j in (i * i..size).step_by(i) {
                is_prime[j] = false;
            }
        }
    }

    is_prime
}

fn sqrt_u32(x: u32) -> u32 {
    let mut x = x;
    let mut m: u32 = 1 << 30;
    let mut r: u32 = 0;
    let mut nr: u32;

    loop {
        nr = m + r;
        r >>= 1;
        if nr <= x {
            x -= nr;
            r += m;
        }
        m >>= 2;
        if m == 0 {
            break;
        }
    }

    r
}

fn get_minimum_distance(from: usize, to: usize, edges: &Vec<Vec<Edge>>) -> Option<u32> {
    struct Element {
        point: usize,
        time: u32,
    }
    impl Ord for Element {
        fn cmp(&self, other: &Element) -> Ordering {
            other.time.cmp(&self.time)
        }
    }
    impl PartialOrd for Element {
        fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
            Some(other.time.cmp(&self.time))
        }
    }
    impl PartialEq for Element {
        fn eq(&self, other: &Self) -> bool {
            self.time == other.time
        }
    }
    impl Eq for Element {}

    let n = edges.len();
    let mut heap: BinaryHeap<Element> = BinaryHeap::new();
    let mut d: Vec<u32> = vec![u32::MAX; n];

    heap.push(Element {
        point: from,
        time: 0,
    });
    d[from] = 0;
    while !heap.is_empty() {
        let elem = heap.pop().unwrap();
        let p = elem.point;
        let t = elem.time;

        if d[p] < t {
            continue;
        }
        if p == to {
            return Some(t);
        }

        for e in edges[p].iter() {
            let nx = e.0;
            let nt = t + e.1;
            if d[nx] > nt {
                heap.push(Element {
                    point: nx,
                    time: nt,
                });
                d[nx] = nt;
            }
        }
    }

    None
}

fn get_input() -> Vec<Point> {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().flat_map(str::parse::<i32>);
    let mut get = || iter.next().unwrap();

    let mut points: Vec<Point> = Vec::new();
    points.push(Point(get(), get()));
    points.push(Point(get(), get()));

    let n = get();
    for _ in 0..n {
        points.push(Point(get(), get()));
    }

    points
}
