fn main() {
    let grade = get_input();
    let score = get_score(grade);
    println!("{:.1}", score);
}

fn get_input() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn get_score(grade: String) -> f32 {
    if grade.eq("A+") {
        4.3
    } else if grade.eq("A0") {
        4.0
    } else if grade.eq("A-") {
        3.7
    } else if grade.eq("B+") {
        3.3
    } else if grade.eq("B0") {
        3.0
    } else if grade.eq("B-") {
        2.7
    } else if grade.eq("C+") {
        2.3
    } else if grade.eq("C0") {
        2.0
    } else if grade.eq("C-") {
        1.7
    } else if grade.eq("D+") {
        1.3
    } else if grade.eq("D0") {
        1.0
    } else if grade.eq("D-") {
        0.7
    } else {
        0.0
    }
}
