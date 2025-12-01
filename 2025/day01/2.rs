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
            'L' => {
                for _ in 0..n {
                    a -= 1;
                    if a < 0 {
                        a = 99;
                    }
                    if a == 0 {
                        ans += 1;
                    }
                }
            }
            'R' => {
                for _ in 0..n {
                    a += 1;
                    if a >= 100 {
                        a = 0;
                    }
                    if a == 0 {
                        ans += 1;
                    }
                }
            }
            _ => panic!("Invalid input"),
        }
    }

    println!("{}", ans);
}
