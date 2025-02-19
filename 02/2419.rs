use std::cell::RefCell;

fn main() {
    let (candies, m) = get_input();
    let answer = get_answer(candies, m);
    println!("{}", answer);
}

fn get_input() -> (Vec<i16>, u32) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<u32>);
    let mut get = || iter.next().unwrap();

    let (n, m) = (get(), get());

    let candies = (0..n)
        .map(|_| {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            let candy = input.trim().parse::<i16>().unwrap();

            candy
        })
        .collect();

    (candies, m)
}

fn get_answer(candies: Vec<i16>, m: u32) -> u32 {
    let n = candies.len();
    let solver = Solver::new(candies, m);

    let mut left = 0;
    let mut right = n + 1;

    while right - left > 5 {
        let mid_left = (right - left) / 3 + left;
        let mid_right = (right - left) / 3 * 2 + left;

        let res_ml = solver.get_max_candy(mid_left);
        let res_mr = solver.get_max_candy(mid_right);

        if res_ml < res_mr {
            left = mid_left;
        } else {
            right = mid_right + 1;
        }
    }

    let mut answer = 0;
    for i in left..right {
        answer = answer.max(solver.get_max_candy(i));
    }
    answer as u32
}

struct Solver {
    pos_candies: Vec<i16>,
    neg_candies: Vec<i16>,
    m: u64,
    max_candy_table: Vec<RefCell<Option<i32>>>,
}

impl Solver {
    fn new(candies: Vec<i16>, m: u32) -> Self {
        let max_candy_table = vec![RefCell::new(None); candies.len() + 1];

        let mut pos_candies: Vec<_> = candies
            .iter()
            .filter_map(|c| if *c >= 0 { Some(*c) } else { None })
            .collect();
        pos_candies.sort();

        let mut neg_candies: Vec<_> = candies
            .into_iter()
            .filter_map(|c| if c < 0 { Some(-c) } else { None })
            .collect();
        neg_candies.sort();

        Solver {
            pos_candies,
            neg_candies,
            m: m as u64,
            max_candy_table,
        }
    }

    fn get_max_candy(&self, n_candy_group_to_eat: usize) -> i32 {
        {
            let res = self.max_candy_table[n_candy_group_to_eat].borrow();
            if res.is_some() {
                return res.unwrap();
            }
        }

        let res = self.calc_max_candy(n_candy_group_to_eat);
        let mut ptr = self.max_candy_table[n_candy_group_to_eat].borrow_mut();
        *ptr = Some(res);

        res
    }

    fn calc_max_candy(&self, remain: usize) -> i32 {
        let pos_n = self.pos_candies.len();
        let neg_n = self.neg_candies.len();
        let mut dp = vec![0; (pos_n + 1) * (neg_n + 1) * 2];
        let idx = |pos_idx: usize, neg_idx: usize, is_pos: bool| {
            (pos_idx * (neg_n + 1) + neg_idx) * 2 + if is_pos { 1 } else { 0 }
        };

        dp[idx(0, 0, false)] = i32::MAX;
        dp[idx(0, 0, true)] = i32::MAX;

        for i in 0..remain {
            let mut pi = i.min(pos_n);
            let mut ni = i.saturating_sub(pos_n);

            loop {
                for way in 0..2 {
                    let is_pos = way == 1;
                    let current = dp[idx(pi, ni, is_pos)];
                    let current_x = if is_pos {
                        if pi == 0 {
                            0
                        } else {
                            self.pos_candies[pi - 1]
                        }
                    } else {
                        if ni == 0 {
                            0
                        } else {
                            -self.neg_candies[ni - 1]
                        }
                    };

                    if pi < pos_n {
                        let next_x = self.pos_candies[pi];
                        let loss = (remain - i) as i32 * current_x.abs_diff(next_x) as i32;
                        let ptr = &mut dp[idx(pi + 1, ni, true)];
                        *ptr = (*ptr).max(current - loss);
                    }
                    if ni < neg_n {
                        let next_x = -self.neg_candies[ni];
                        let loss = (remain - i) as i32 * current_x.abs_diff(next_x) as i32;
                        let ptr = &mut dp[idx(pi, ni + 1, false)];
                        *ptr = (*ptr).max(current - loss);
                    }
                }

                if pi == 0 || ni == neg_n {
                    break;
                }
                pi -= 1;
                ni += 1;
            }
        }

        let mut res = 0;
        let mut pi = remain.min(pos_n);
        let mut ni = remain.saturating_sub(pos_n);

        loop {
            for way in 0..2 {
                let is_pos = way == 1;
                let current = dp[idx(pi, ni, is_pos)];
                res = res.max(current);
            }

            if pi == 0 || ni == neg_n {
                break;
            }
            pi -= 1;
            ni += 1;
        }

        (remain as i32 * self.m as i32) - (i32::MAX - res)
    }
}
