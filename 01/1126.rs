const MAX_SUM_HEIGHT: usize = 500000;

fn main() {
    let blocks = get_input();
    let answer = get_answer(blocks);

    match answer {
        0 => println!("-1"),
        x => println!("{}", x),
    }
}

fn get_input() -> Vec<i32> {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let blocks = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<i32>)
        .collect();

    blocks
}

fn get_answer(blocks: Vec<i32>) -> i32 {
    // dp[i][j] = i번째 블록까지 처리했으며 두 블록 탑의 높이 차가 j일 때, 둘 중 더 높은 블록 탑의 높이 중 가능한 최댓값. 불가능한 경우 -1.
    // 0 <= i <= n, 0 <= j <= 500000
    let mut d0 = vec![-1; MAX_SUM_HEIGHT + 1];
    let mut d1 = vec![-1; MAX_SUM_HEIGHT + 1];

    d0[0] = 0;

    let update_height = |dst: &mut Vec<i32>, diff: i32, best_height: i32| {
        let diff = diff as usize;
        if diff <= MAX_SUM_HEIGHT {
            dst[diff] = dst[diff].max(best_height);
        }
    };

    for i in 0..blocks.len() {
        let (dst, src) = if i & 1 > 0 {
            (&mut d0, &d1)
        } else {
            (&mut d1, &d0)
        };

        let block_height = blocks[i];

        for j in 0..MAX_SUM_HEIGHT + 1 {
            let best_height = src[j];
            let diff = j as i32;
            if best_height != -1 {
                update_height(dst, diff + block_height, best_height + block_height);
                update_height(
                    dst,
                    (diff - block_height).abs(),
                    best_height.max(best_height - diff + block_height),
                );
                update_height(dst, diff, best_height);
            }
        }
    }

    let res = if blocks.len() & 1 > 0 { d1[0] } else { d0[0] };
    res
}
