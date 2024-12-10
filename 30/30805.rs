fn main() {
    let (a, b) = get_input();
    let ans = get_answer(&a, &b);

    println!("{}", ans.len());
    for v in ans.into_iter() {
        print!("{} ", v);
    }
    println!("");
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

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let b = input
        .split_ascii_whitespace()
        .flat_map(str::parse::<u32>)
        .collect();

    (a, b)
}

fn get_answer(a: &Vec<u32>, b: &Vec<u32>) -> Vec<u32> {
    let mut answer = Vec::new();

    let mut tree_a = BinaryTree::new(a);
    let mut tree_b = BinaryTree::new(b);

    let mut del_a = 0;
    let mut del_b = 0;

    while tree_a.is_empty() == false && tree_b.is_empty() == false {
        let (val_a, idx_a) = tree_a.get();
        let (val_b, idx_b) = tree_b.get();

        if val_a > val_b {
            tree_a.remove(idx_a);
        } else if val_a < val_b {
            tree_b.remove(idx_b);
        } else {
            for i in del_a..(idx_a + 1) {
                tree_a.remove(i);
            }
            for i in del_b..(idx_b + 1) {
                tree_b.remove(i);
            }
            del_a = idx_a + 1;
            del_b = idx_b + 1;

            answer.push(val_a);
        }
    }

    answer
}

struct BinaryTree {
    offset: usize,
    tree: Vec<Option<Element>>,
}

#[derive(Clone, PartialEq, PartialOrd, Eq)]
struct Element {
    val: u32,
    idx: usize,
}

impl Ord for Element {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.val
            .cmp(&other.val)
            .then(self.idx.cmp(&other.idx).reverse())
    }
}

impl BinaryTree {
    fn new(arr: &Vec<u32>) -> Self {
        let n = arr.len();

        let mut offset = n;
        while (offset & (offset - 1)) > 0 {
            offset += offset & (!offset + 1);
        }

        let mut tree = vec![None; offset * 2];
        for i in 0..n {
            tree[offset + i] = Some(Element {
                val: arr[i],
                idx: i,
            });
        }

        let mut bt = BinaryTree { offset, tree };

        for i in (1..offset).rev() {
            bt.update(i);
        }

        bt
    }

    fn is_empty(&self) -> bool {
        self.tree[1].is_none()
    }

    fn get(&self) -> (u32, usize) {
        let root = self.tree[1].as_ref().unwrap();
        (root.val, root.idx)
    }

    fn remove(&mut self, idx: usize) -> () {
        self.tree[idx + self.offset] = None;

        let mut idx = (idx + self.offset) / 2;
        while idx > 0 {
            self.update(idx);
            idx /= 2;
        }
    }

    fn update(&mut self, idx: usize) -> () {
        let left = self.tree[idx * 2].as_ref();
        let right = self.tree[idx * 2 + 1].as_ref();
        self.tree[idx] = match (left, right) {
            (None, None) => None,
            (None, Some(rhs)) => Some(rhs.clone()),
            (Some(lhs), None) => Some(lhs.clone()),
            (Some(lhs), Some(rhs)) => Some(lhs.max(rhs).clone()),
        };
    }
}
