const MAX_WEIGHT: u32 = 15000;

fn main() {
    let (weights, marbles) = get_input();

    let checker = Checker::new(weights);

    for marble in marbles {
        print!("{} ", if checker.is_able(marble) { 'Y' } else { 'N' });
    }
    println!("");
}

struct Checker {
    table: Vec<bool>,
}

impl Checker {
    fn new(weights: Vec<u32>) -> Checker {
        let mut vec: Vec<bool> = vec![false; (MAX_WEIGHT + 1) as usize];
        let mut buf: Vec<bool> = vec![false; (MAX_WEIGHT + 1) as usize];
        let update = |x: i32, buf: &mut Vec<bool>| {
            let idx = i32::abs(x) as usize;
            buf[idx] = true;
        };
        vec[0] = true;
        buf[0] = true;

        for weight in weights {
            for i in 0..=(MAX_WEIGHT as usize) {
                if vec[i] == true {
                    let i = i as i32;
                    let weight = weight as i32;
                    update(i + weight, &mut buf);
                    update(i, &mut buf);
                    update(i - weight, &mut buf);
                }
            }

            let tmp: Vec<bool> = vec;
            vec = buf;
            buf = tmp;
        }

        let checker = Checker { table: vec };
        checker
    }

    fn is_able(&self, weight: u32) -> bool {
        if weight <= MAX_WEIGHT {
            self.table[weight as usize]
        } else {
            false
        }
    }
}

fn get_input() -> (Vec<u32>, Vec<u32>) {
    let buf = std::io::read_to_string(std::io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let n_weight = get();
    let mut weights: Vec<u32> = vec![0; n_weight];

    for i in 0..n_weight {
        weights[i] = u32::try_from(get()).unwrap();
    }

    let n_marble = get();
    let mut marbles: Vec<u32> = vec![0; n_marble];

    for i in 0..n_marble {
        marbles[i] = u32::try_from(get()).unwrap();
    }

    (weights, marbles)
}
