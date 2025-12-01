use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let reader = stdin.lock();

    let mut a: i32 = 50;
    let mut ans: i32 = 0;

    for line in reader.lines() {
        let text = line.unwrap();
        let c = text.chars().nth(0).unwrap();
        let n: i32 = text[1..].trim().parse().unwrap();

        match c {
            'L' => a -= n,
            'R' => a += n,
            _ => panic!("Invalid input"),
        }

        a = (a + 100) % 100;
        if a == 0 {
            ans += 1;
        }
    }

    println!("{}", ans);
}
