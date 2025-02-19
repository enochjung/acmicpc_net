fn main() {
    let (n, students) = get_input();
    let answer = get_answer(n, students);
    println!("{}", answer);
}

fn get_input() -> (usize, [Vec<u32>; 3]) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<usize>().unwrap();

    let students = (0..3)
        .map(|_| {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            input
                .split_ascii_whitespace()
                .flat_map(str::parse::<u32>)
                .map(|x| x - 1)
                .collect()
        })
        .collect::<Vec<_>>()
        .try_into()
        .unwrap();

    (n, students)
}

fn get_answer(n: usize, students: [Vec<u32>; 3]) -> u32 {
    let mut scores = vec![[0, 0, 0]; n];
    for class_id in 0..3 {
        for rank in 0..n {
            let student_id = students[class_id][rank] as usize;
            scores[student_id][class_id] = (n - rank) as u32;
        }
    }
    scores.sort_by(|a, b| a[2].cmp(&b[2]).reverse());

    let mut answer = 0;
    let mut tree = BinaryIndexedTree::new(n);

    scores.into_iter().for_each(|[x, height, _]| {
        let x = x as usize;
        let tree_height = tree.get_max(x - 1);
        if height > tree_height {
            tree.update_until(x, height);
            answer += 1;
        }
    });

    answer
}

struct BinaryIndexedTree {
    tree: Vec<u32>,
}

impl BinaryIndexedTree {
    fn new(n: usize) -> Self {
        let tree = vec![0; n + 1];
        BinaryIndexedTree { tree }
    }

    fn get_max(&self, idx: usize) -> u32 {
        let mut max = 0;
        let mut idx = idx + 1;

        while idx < self.tree.len() {
            max = max.max(self.tree[idx]);
            idx += idx & (!idx + 1);
        }

        max
    }

    fn update_until(&mut self, idx: usize, val: u32) -> () {
        let mut idx = idx;

        while idx > 0 {
            self.tree[idx] = self.tree[idx].max(val);
            idx -= idx & (!idx + 1);
        }
    }
}
