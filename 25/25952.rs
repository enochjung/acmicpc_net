use std::collections::HashMap;

const MAX_N: u64 = 70000;
const THRESHOLD: usize = 200;

fn main() {
    let points = get_input();
    let compressed_points = compress(&points);
    let num = count_rectangles(&compressed_points);
    println!("{}", num);
}

fn get_input() -> Vec<(u32, u32)> {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace();
    let mut get = || iter.next().unwrap();

    let n = str::parse::<usize>(get()).unwrap();
    let mut points: Vec<(u32, u32)> = vec![(0, 0); n];

    for point in points.iter_mut() {
        let x = str::parse::<u32>(get()).unwrap();
        let y = str::parse::<u32>(get()).unwrap();
        *point = (x, y);
    }

    points
}

fn compress(points: &[(u32, u32)]) -> Vec<Vec<u32>> {
    let (mut xs, mut ys): (Vec<_>, Vec<_>) = points.iter().cloned().unzip();

    xs.sort();
    xs.dedup();
    ys.sort();
    ys.dedup();

    let shape = (xs.len(), ys.len());
    let mut compressed_points: Vec<Vec<u32>> = vec![Vec::new(); shape.1];

    for point in points.iter() {
        let (x, y) = point;
        let x_idx = xs.binary_search(x).unwrap() as u32;
        let y_idx = ys.binary_search(y).unwrap() as u32;

        compressed_points[y_idx as usize].push(x_idx);
    }

    for x_points in compressed_points.iter_mut() {
        x_points.sort();
    }
    compressed_points.sort_by_key(|v| v.len());

    compressed_points
}

fn count_rectangles(points: &[Vec<u32>]) -> u32 {
    let small_idx = match points.binary_search_by_key(&THRESHOLD, |v| v.len()) {
        Ok(idx) => idx,
        Err(idx) => idx,
    };

    let small_points = &points[..small_idx];
    let large_points = &points[small_idx..];

    count_rectangles_in_small_case(small_points)
        + count_rectangles_in_large_case(large_points)
        + count_rectangles_between_small_large_case(small_points, large_points)
}

fn count_rectangles_in_small_case(small_points: &[Vec<u32>]) -> u32 {
    let mut set: HashMap<u64, u32> = HashMap::new();
    let mut num_rectangles: u32 = 0;

    for xs in small_points {
        let len = xs.len();

        for i in 0..len.saturating_sub(1) {
            for j in i + 1..len {
                let (a, b) = (xs[i] as u64, xs[j] as u64);
                let key = a + b * MAX_N;

                num_rectangles += match set.get_mut(&key) {
                    Some(value) => {
                        let res = value.clone();
                        *value += 1;
                        res
                    }
                    None => {
                        set.insert(key, 1);
                        0
                    }
                };
            }
        }
    }

    num_rectangles
}

fn count_rectangles_in_large_case(large_points: &[Vec<u32>]) -> u32 {
    let mut num_rectangles: u32 = 0;

    let len = large_points.len();
    for i in 0..len.saturating_sub(1) {
        for j in i + 1..len {
            let n_dup = count_duplicate(&large_points[i], &large_points[j]);
            num_rectangles += combination_2(n_dup);
        }
    }

    num_rectangles
}

fn count_rectangles_between_small_large_case(
    small_points: &[Vec<u32>],
    large_points: &[Vec<u32>],
) -> u32 {
    let mut num_rectangles: u32 = 0;

    for xs in small_points.iter() {
        for lxs in large_points.iter() {
            let n_dup = count_duplicate(xs, lxs);
            num_rectangles += combination_2(n_dup);
        }
    }

    num_rectangles
}

fn count_duplicate(a: &[u32], b: &[u32]) -> u32 {
    let (a, b) = match a.len() < b.len() {
        true => (a, b),
        false => (b, a),
    };

    a.iter().filter_map(|x| b.binary_search(x).ok()).count() as u32
}

fn combination_2(n: u32) -> u32 {
    match n {
        0 => 0,
        x => x * (x - 1) / 2,
    }
}
