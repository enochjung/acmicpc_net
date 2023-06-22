const N_OF_STUDENT: usize = 30;

fn main() {
    let is_submit = get_input();
    let missed = is_submit
        .into_iter()
        .enumerate()
        .filter_map(|(id, s)| if s { None } else { Some(id) });

    for id in missed {
        println!("{}", id + 1);
    }
    println!("");
}

fn get_input() -> Vec<bool> {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let mut is_submit: Vec<bool> = vec![false; N_OF_STUDENT];

    for _ in 0..N_OF_STUDENT - 2 {
        let id = get() - 1;
        is_submit[id] = true;
    }

    is_submit
}
