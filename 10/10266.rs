const CYCLE: u32 = 360000;

fn main() {
    let (a, b) = get_input();
    let answer = get_answer(a, b);
    if answer {
        println!("possible");
    } else {
        println!("impossible");
    }
}

fn get_input() -> (Vec<u32>, Vec<u32>) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let a = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<u32>)
        .collect();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let b = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<u32>)
        .collect();

    (a, b)
}

fn get_answer(a: Vec<u32>, b: Vec<u32>) -> bool {
    let mut a = a;
    let mut b = b;
    a.sort();
    b.sort();

    b = b
        .clone()
        .into_iter()
        .chain(b.into_iter().map(|x| x + CYCLE))
        .collect();

    for i in 1..a.len() {
        a[i - 1] = a[i] - a[i - 1];
    }
    a.pop();

    for i in 1..b.len() {
        b[i - 1] = b[i] - b[i - 1];
    }
    b.pop();

    kmp::is_included(&b, &a)
}

mod kmp {
    fn build_mismatch_table<T: std::cmp::PartialEq>(pattern: &Vec<T>) -> Vec<i32> {
        let mut table = vec![0; pattern.len() + 1];
        table[0] = -1;

        let mut c = 0;
        for i in 1..pattern.len() {
            if pattern[i] == pattern[c as usize] {
                table[i] = table[c as usize];
            } else {
                table[i] = c;
                while c >= 0 && pattern[i] != pattern[c as usize] {
                    c = table[c as usize];
                }
            }
            c += 1;
        }
        table[pattern.len()] = c;

        table
    }

    pub fn is_included<T: std::cmp::PartialEq>(text: &Vec<T>, pattern: &Vec<T>) -> bool {
        let table = build_mismatch_table(pattern);

        let mut m = 0;
        let mut i = 0;

        while m + i < text.len() {
            if text[m + i] == pattern[i] {
                i += 1;
                if i == pattern.len() {
                    return true;
                }
            } else {
                m = ((m + i) as i32 - table[i]) as usize;
                i = table[i].max(0) as usize;
            }
        }

        false
    }
}
