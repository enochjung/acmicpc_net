use std::fmt::Write;

const STR_MAXLEN: usize = 1000;
const NODE_SIZE: usize = 26 + 1;
const BUFFER_MAX: usize = NODE_SIZE * (4000 * STR_MAXLEN + 1);

fn main() {
    let (colors, nicknames, teams) = get_input();

    let mut prefix_trie = Trie::new();
    for color in colors.lines() {
        prefix_trie.build(color.chars());
    }

    let mut suffix_trie = Trie::new();
    for nickname in nicknames.lines() {
        suffix_trie.build(nickname.chars().rev());
    }

    let mut output = String::new();
    for team in teams.lines() {
        let res = if is_valid(team, &prefix_trie, &suffix_trie) {
            "Yes"
        } else {
            "No"
        };
        writeln!(output, "{res}").unwrap();
    }
    print!("{output}");
}

fn get_input() -> (String, String, String) {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut get = || iter.next().unwrap();

    let (c, n) = (get(), get());

    let mut colors = String::new();
    for _ in 0..c {
        std::io::stdin().read_line(&mut colors).unwrap();
    }

    let mut nicknames = String::new();
    for _ in 0..n {
        std::io::stdin().read_line(&mut nicknames).unwrap();
    }

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let q = input.trim().parse::<usize>().unwrap();

    let mut teams = String::new();
    for _ in 0..q {
        std::io::stdin().read_line(&mut teams).unwrap();
    }

    (colors, nicknames, teams)
}

struct Trie {
    len: usize,
    nodes: Vec<u32>,
}

enum TrackingState {
    Matched,
    Mismatched,
    Quit,
}

impl Trie {
    fn new() -> Self {
        Trie {
            len: 1,
            nodes: vec![0; BUFFER_MAX],
        }
    }

    fn build(&mut self, str_iter: impl Iterator<Item = char>) -> () {
        let mut node_idx = 0;

        for ch in str_iter {
            let ch_idx = ch as usize - 'a' as usize;
            let idx = node_idx * NODE_SIZE + ch_idx;

            if self.nodes[idx] == 0 {
                self.nodes[idx] = self.len as u32;
                self.len += 1;
            }

            node_idx = self.nodes[idx] as usize;
        }

        let endpoint_idx = node_idx * NODE_SIZE + NODE_SIZE - 1;
        self.nodes[endpoint_idx] = 1;
    }

    fn tracking_iter<'a: 'b, 'b>(
        &'a self,
        str_iter: impl Iterator<Item = char> + 'b,
    ) -> impl Iterator<Item = TrackingState> + 'b {
        let mut node_idx = 0;
        let mut failed = false;

        str_iter.map(move |ch| {
            if failed {
                return TrackingState::Quit;
            }

            let ch_idx = ch as usize - 'a' as usize;
            let idx = node_idx * NODE_SIZE + ch_idx;

            if self.nodes[idx] == 0 {
                failed = true;
                return TrackingState::Quit;
            }

            node_idx = self.nodes[idx] as usize;

            let endpoint_idx = node_idx * NODE_SIZE + NODE_SIZE - 1;
            if self.nodes[endpoint_idx] == 1 {
                TrackingState::Matched
            } else {
                TrackingState::Mismatched
            }
        })
    }
}

fn is_valid(target: &str, prefix_trie: &Trie, suffix_trie: &Trie) -> bool {
    if target.len() <= 1 {
        return false;
    }

    let mut prefix_table = vec![false; STR_MAXLEN];

    let mut prefix_iter = prefix_trie.tracking_iter(target.chars());
    let suffix_iter = suffix_trie.tracking_iter(target.chars().rev());

    let mut prefix_last_valid_idx = 0;
    for i in 0..STR_MAXLEN {
        match prefix_iter.next() {
            Some(TrackingState::Matched) => prefix_table[i] = true,
            Some(TrackingState::Mismatched) => {}
            _ => break,
        }
        prefix_last_valid_idx = i;
    }
    prefix_last_valid_idx = prefix_last_valid_idx.min(target.len() - 2);

    let skip_cnt = target.len() - prefix_last_valid_idx - 2;
    let mut prefix_idx = prefix_last_valid_idx;

    for state in suffix_iter.skip(skip_cnt) {
        match state {
            TrackingState::Matched => {
                if prefix_table[prefix_idx] {
                    return true;
                }
            }
            TrackingState::Mismatched => {}
            TrackingState::Quit => break,
        }
        if prefix_idx == 0 {
            break;
        }
        prefix_idx -= 1;
    }

    false
}
