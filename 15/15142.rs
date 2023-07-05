fn main() {
    let n = get_input();
    let decompositions = get_decompositions(n);

    if decompositions == None {
        println!("-1");
    } else {
        let decompositions = decompositions.unwrap();
        println!("{}", decompositions.len());
        for decomposition in decompositions.iter() {
            print!("{} ", decomposition.len());
            for num in decomposition.iter() {
                print!("{num} ");
            }
            println!("");
        }
    }
}

fn get_decompositions(n: u64) -> Option<Vec<Vec<u64>>> {
    if n & (n - 1) == 0 {
        return None;
    }

    Some(
        (1..=60)
            .filter_map(|i| get_ith_decomposition(n, i))
            .collect(),
    )
}

fn get_ith_decomposition(n: u64, i: u32) -> Option<Vec<u64>> {
    let mut res: Vec<u64> = Vec::new();

    let a = ith_root(n, i);
    let b = a + 1;
    let mut n = n;

    if a == 1 {
        return None;
    }

    while n % a == 0 {
        res.push(a);
        n /= a;
    }
    while n % b == 0 {
        res.push(b);
        n /= b;
    }

    if n == 1 && res.len() == usize::try_from(i).unwrap() {
        Some(res)
    } else {
        None
    }
}

fn ith_root(n: u64, i: u32) -> u64 {
    let mut low: u64 = 1;
    let mut high: u64 = 1 << 61;

    while low + 1 < high {
        let mid = (low + high) / 2;
        if pow(mid, i) <= n {
            low = mid;
        } else {
            high = mid;
        }
    }

    low
}

fn pow(a: u64, b: u32) -> u64 {
    let mut x: u64 = 1;
    let mut m: u64 = a;
    let mut b: u32 = b;

    while b > 0 {
        if b & 1 > 0 {
            let xm = x.checked_mul(m);
            x = if xm == None { u64::MAX } else { xm.unwrap() };
        }
        b >>= 1;
        let mm = m.checked_mul(m);
        m = if mm == None { u64::MAX } else { mm.unwrap() };
    }

    x
}

fn get_input() -> u64 {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().parse::<u64>().unwrap()
}
