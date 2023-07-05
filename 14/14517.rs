const MOD: u32 = 10007;

fn main() {
    let input = get_input();
    let mut counter = PalindromeCounter::new(&input);
    println!("{}", counter.get());
}

struct PalindromeCounter {
    arr: Vec<u8>,
    dp: Vec<Vec<Vec<Option<u32>>>>,
}

impl PalindromeCounter {
    pub fn new(string: &String) -> PalindromeCounter {
        let n = string.len();
        PalindromeCounter {
            arr: string.trim().as_bytes().to_vec(),
            dp: vec![vec![vec![None; 3]; n + 1]; n],
        }
    }

    pub fn get(&mut self) -> u32 {
        let n = self.arr.len();
        self.get_element(0, n, 0)
    }

    fn get_element(&mut self, from: usize, to: usize, code: usize) -> u32 {
        if self.dp[from][to][code] != None {
            return self.dp[from][to][code].unwrap();
        }
        if from >= to {
            return 0;
        }
        if from + 1 == to {
            return 1;
        }

        let mut value: u32 = 0;
        if self.arr[from] == self.arr[to - 1] {
            value += self.get_element(from + 1, to - 1, 0) + 1;
        }
        if code == 0 {
            value += self.get_element(from + 1, to - 1, 0);
            value += self.get_element(from, to - 1, 1);
            value += self.get_element(from + 1, to, 2);
        } else if code == 1 {
            value += self.get_element(from, to - 1, 1);
        } else {
            value += self.get_element(from + 1, to, 2);
        }

        value %= MOD;
        self.dp[from][to][code] = Some(value);
        value
    }
}

fn get_input() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input
}
