fn main() {
    let (n, s, m, l, xl, xxl, xxxl, t, p) = get_input();

    let a = get_answer1(s, m, l, xl, xxl, xxxl, t);
    let (d, r) = get_answer2(n, p);

    println!("{}", a);
    println!("{} {}", d, r);
}

fn get_input() -> (u32, u32, u32, u32, u32, u32, u32, u32, u32) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<u32>().unwrap();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<u32>);
    let mut get = || iter.next().unwrap();

    let s = get();
    let m = get();
    let l = get();
    let xl = get();
    let xxl = get();
    let xxxl = get();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<u32>);
    let mut get = || iter.next().unwrap();

    let t = get();
    let p = get();

    (n, s, m, l, xl, xxl, xxxl, t, p)
}

fn get_answer1(s: u32, m: u32, l: u32, xl: u32, xxl: u32, xxxl: u32, t: u32) -> u32 {
    let num_s = (s + t - 1) / t;
    let num_m = (m + t - 1) / t;
    let num_l = (l + t - 1) / t;
    let num_xl = (xl + t - 1) / t;
    let num_xxl = (xxl + t - 1) / t;
    let num_xxxl = (xxxl + t - 1) / t;

    num_s + num_m + num_l + num_xl + num_xxl + num_xxxl
}

fn get_answer2(n: u32, p: u32) -> (u32, u32) {
    let d = n / p;
    let r = n % p;

    (d, r)
}
