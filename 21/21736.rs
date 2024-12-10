fn main() {
    let (n, m, position, mut map) = get_input();
    let num = travel(n, m, position, &mut map);

    if num == 0 {
        println!("TT");
    } else {
        println!("{}", num);
    }
}

#[derive(PartialEq)]
enum Space {
    Empty,
    Person,
    Visited,
    Wall,
}

fn get_input() -> (i32, i32, i32, Vec<Space>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let mut get = || iter.next().unwrap();

    let (n, m) = (get(), get());

    let mut input = String::new();
    for _ in 0..n {
        std::io::stdin().read_line(&mut input).unwrap();
    }

    let mut position = 0;
    let mut map = Vec::with_capacity((n * m) as usize);
    for ch in input.as_bytes() {
        match ch {
            b'O' => map.push(Space::Empty),
            b'X' => map.push(Space::Wall),
            b'I' => {
                position = map.len() as i32;
                map.push(Space::Empty);
            }
            b'P' => map.push(Space::Person),
            _ => {}
        }
    }

    (n, m, position, map)
}

fn travel(n: i32, m: i32, position: i32, map: &mut Vec<Space>) -> u32 {
    let x = position / m;
    let y = position % m;
    let position = position as usize;

    let mut cnt = if map[position] == Space::Person { 1 } else { 0 };
    map[position] = Space::Visited;

    [(-1, 0), (1, 0), (0, -1), (0, 1)]
        .into_iter()
        .for_each(|(dx, dy)| {
            let tx = x + dx;
            let ty = y + dy;
            if 0 <= tx && tx < n as i32 && 0 <= ty && ty < m as i32 {
                let tp = (tx * m + ty) as usize;
                if map[tp] != Space::Wall && map[tp] != Space::Visited {
                    cnt += travel(n, m, tp as i32, map);
                }
            }
        });

    cnt
}
