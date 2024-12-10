fn main() {
    let numbers = get_input();
    println!("{}", get_num_of_palindrome(&numbers[..]));
}

fn get_num_of_palindrome(s: &[u32]) -> u32 {
    fn f(s: &[u32]) -> u32 {
        let len = s.len() as u32;
        match len {
            0 => 1,
            1 => s[0] + 1,
            _ => {
                s[0] * 10_u32.pow((len - 1) / 2)
                    + if s[0] <= s[s.len() - 1] {
                        f(&s[1..(s.len() - 1)])
                    } else {
                        g(&s[1..(s.len() - 1)])
                    }
            }
        }
    }

    fn g(s: &[u32]) -> u32 {
        let len = s.len() as u32;
        match len {
            0 => 0,
            1 => s[0],
            _ => {
                s[0] * 10_u32.pow((len - 1) / 2)
                    + if s[0] < s[s.len() - 1] {
                        f(&s[1..(s.len() - 1)])
                    } else {
                        g(&s[1..(s.len() - 1)])
                    }
            }
        }
    }

    let len = s.len() as u32;
    match len {
        1 => s[0],
        _ => {
            s[0] * 10_u32.pow((len - 1) / 2) + 10_u32.pow(len / 2) - 2
                + if s[0] <= s[s.len() - 1] {
                    f(&s[1..(s.len() - 1)])
                } else {
                    g(&s[1..(s.len() - 1)])
                }
        }
    }
}

fn get_input() -> Vec<u32> {
    let mut input = String::new();
    let _ = std::io::stdin().read_line(&mut input);
    input.chars().map_while(|c| c.to_digit(10)).collect()
}
