fn main() {
    let cases = get_input();

    for students in cases {
        let num = u32::try_from(students.len()).unwrap();
        let avg = students.iter().fold(0, |sum, x| sum + x) / num;
        let cnt = students.iter().filter(|x| x > &&avg).count();
        let ratio = (cnt as f32) / (num as f32);
        println!("{:.3}%", ratio * 100.0);
    }
}

fn get_input() -> Vec<Vec<u32>> {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let n_of_case = get();
    let mut cases: Vec<Vec<u32>> = Vec::new();

    for _ in 0..n_of_case {
        let n_of_student = get();
        let mut scores: Vec<u32> = Vec::new();

        for _ in 0..n_of_student {
            let score = u32::try_from(get()).unwrap();
            scores.push(score);
        }

        cases.push(scores);
    }

    cases
}
