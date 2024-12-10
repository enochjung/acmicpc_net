mod kmp {
    pub struct ComparisonResult {
        start_index: usize,
        length: usize,
    }

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

    pub fn find_all<T: std::cmp::PartialEq>(text: &Vec<T>, pattern: &Vec<T>) -> Vec<usize> {
        let table = build_mismatch_table(pattern);

        let mut res = Vec::new();

        let mut m = 0;
        let mut i = 0;

        while m + i < text.len() {
            if text[m + i] == pattern[i] {
                i += 1;
                if i == pattern.len() {
                    res.push(m);
                    m = ((m + i) as i32 - table[i]) as usize;
                    i = table[i] as usize;
                }
            } else {
                m = ((m + i) as i32 - table[i]) as usize;
                i = table[i].max(0) as usize;
            }
        }

        res
    }

    pub fn find<T: std::cmp::PartialEq>(text: &Vec<T>, pattern: &Vec<T>) -> ComparisonResult {
        let table = build_mismatch_table(pattern);

        let mut res = ComparisonResult {
            start_index: 0,
            length: 0,
        };

        let mut m = 0;
        let mut i = 0;

        while m + i < text.len() {
            if text[m + i] == pattern[i] {
                i += 1;
                if res.length < i {
                    res.start_index = m;
                    res.length = i;
                }
                if i == pattern.len() {
                    break;
                }
            } else {
                m = ((m + i) as i32 - table[i]) as usize;
                i = table[i].max(0) as usize;
            }
        }

        res
    }

    pub fn is_included<T: std::cmp::PartialEq>(text: &Vec<T>, pattern: &Vec<T>) -> bool {
        let res = find(text, pattern);
        res.length == pattern.len()
    }
}
