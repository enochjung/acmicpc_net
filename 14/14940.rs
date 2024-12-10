use std::fmt::Write;

fn main() {
    let (n, m, start, is_wall) = get_input();
    let table = get_distance_table(n, m, start, &is_wall);

    let mut output = String::new();
    for i in 0..(n * m) as usize {
        let time = if is_wall[i] == true { 0 } else { table[i] };

        if i % m as usize == m as usize - 1 {
            write!(output, "{}\n", time).unwrap();
        } else {
            write!(output, "{} ", time).unwrap();
        }
    }
    print!("{}", output);
}

fn get_input() -> (i32, i32, i32, Vec<bool>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut get = || iter.next().unwrap();

    let (n, m) = (get(), get());

    let mut input = String::new();
    for _ in 0..n {
        std::io::stdin().read_line(&mut input).unwrap();
    }

    let mut start = 0;
    let mut is_wall = Vec::with_capacity((n * m) as usize);
    for ch in input.as_bytes() {
        match ch {
            b'0' => is_wall.push(true),
            b'1' => is_wall.push(false),
            b'2' => {
                start = is_wall.len() as i32;
                is_wall.push(false);
            }
            _ => {}
        }
    }

    (n, m, start, is_wall)
}

struct State {
    position: i32,
    time: i32,
}

fn get_distance_table(n: i32, m: i32, start: i32, is_wall: &Vec<bool>) -> Vec<i32> {
    let mut table = vec![-1; (n * m) as usize];
    let mut deque = std::collections::VecDeque::new();

    table[start as usize] = 0;
    deque.push_back(State {
        position: start,
        time: 0,
    });

    loop {
        let now = deque.pop_front();
        if now.is_none() {
            break;
        }
        let now = now.unwrap();
        let x = now.position / m;
        let y = now.position % m;

        [(-1, 0), (1, 0), (0, -1), (0, 1)]
            .into_iter()
            .for_each(|(dx, dy)| {
                let tx = x + dx;
                let ty = y + dy;
                if 0 <= tx && tx < n as i32 && 0 <= ty && ty < m as i32 {
                    let tp = (tx * m + ty) as usize;
                    if is_wall[tp] == false && table[tp] == -1 {
                        table[tp] = now.time + 1;
                        deque.push_back(State {
                            position: tp as i32,
                            time: now.time + 1,
                        });
                    }
                }
            });
    }

    table
}
