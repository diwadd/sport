use std::io::{self, BufRead};

const SQUARE_N: usize = 3;
// const SQUARE_SUM: i32 = 15;

type MagicSquare = [[i32; SQUARE_N]; SQUARE_N];

// fn is_magic(square: &MagicSquare) -> bool {

//     let mut sum_d: i32 = 0;
//     let mut sum_ad: i32 = 0;
//     for i in 0..SQUARE_N {
//         let mut sum_r: i32 = 0;
//         let mut sum_c: i32 = 0;

//         for j in 0..SQUARE_N {
//             sum_r += square[i][j];
//             sum_c += square[j][i];
//         }
//         if sum_r != SQUARE_SUM || sum_c != SQUARE_SUM {
//             return false;
//         }
//         sum_d += square[i][i];
//         sum_ad += square[i][SQUARE_N - i - 1]
//     }

//     if sum_d != SQUARE_SUM || sum_ad != SQUARE_SUM {
//         return false;
//     }

//     return true;
// }

fn calculate_difference(square: &MagicSquare, input: &[Vec<i32>]) -> i32 {

    let mut delta: i32 = 0;
    for i in 0..SQUARE_N {
        for j in 0..SQUARE_N {
            let d: i32 = square[i][j] - input[i][j];
            delta += d.abs();
        }
    }
    return delta;
}

fn forming_magic_square(s: &[Vec<i32>]) -> i32 {


    let all_magic_squares: Vec<MagicSquare> = vec!(
        [[8,1,6],
         [3,5,7],
         [4,9,2]],

        // Horizontal flip
        [[4,9,2],
         [3,5,7],
         [8,1,6]],

        // Horizontal flip 90 rotation
        [[8,3,4],
         [1,5,9],
         [6,7,2]],

        // Vertical flip
        [[6,1,8],
         [7,5,3],
         [2,9,4]],

        // Vertical flip 90 rotation
        [[2,7,6],
         [9,5,1],
         [4,3,8]],

        // 90
        [[4,3,8],
         [9,5,1],
         [2,7,6]],

        // 180
        [[2,9,4],
         [7,5,3],
         [6,1,8]],

        // 270
        [[6,7,2],
         [1,5,9],
         [8,3,4]]
    );
    
    let mut min_val: i32 = std::i32::MAX;
    for square in all_magic_squares {
        // let magic = is_magic(&square);
        // print!("magic: {}\n", magic);
        let delta = calculate_difference(&square, s);
        if delta < min_val {
            min_val = delta;
        }
    }

    return min_val;
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut s: Vec<Vec<i32>> = Vec::with_capacity(3_usize);

    for i in 0..3_usize {
        s.push(Vec::with_capacity(3_usize));

        s[i] = stdin_iterator.next().unwrap().unwrap()
            .trim_end()
            .split(' ')
            .map(|s| s.to_string().parse::<i32>().unwrap())
            .collect();
    }

    let result = forming_magic_square(&s);
    println!("{}", result);
}
