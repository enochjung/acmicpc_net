fn main() {
    let input = get_input();
    let (p_h, p_g) = analyze_message(input);
    let score = get_happiness_score(p_h, p_g);
    println!("{:.2}", (score + f32::EPSILON) * 100.0);
}

fn analyze_message(message: String) -> (u32, u32) {
    let p_h: u32 = message
        .chars()
        .map(|c| if is_happy_character(c) { 1 } else { 0 })
        .sum();
    let p_g: u32 = message
        .chars()
        .map(|c| if is_sad_character(c) { 1 } else { 0 })
        .sum();
    (p_h, p_g)
}

fn is_happy_character(c: char) -> bool {
    match c {
        'H' | 'A' | 'P' | 'Y' => true,
        _ => false,
    }
}

fn is_sad_character(c: char) -> bool {
    match c {
        'S' | 'A' | 'D' => true,
        _ => false,
    }
}

fn get_happiness_score(p_h: u32, p_g: u32) -> f32 {
    if p_h == 0 && p_g == 0 {
        0.5
    } else {
        p_h as f32 / (p_h + p_g) as f32
    }
}

fn get_input() -> String {
    std::io::read_to_string(std::io::stdin()).unwrap()
}
