fn reverse(mut x: i32) -> i32 {

    let mut is_negative: bool = false;

    if x == std::i32::MIN {
        return 0;
    }

    if x < 0 {
        is_negative = true;
        x = -1 * x;
    }

    let mut vec = Vec::new();

    loop {
        let r = x % 10;
        vec.push(r);
        
        x = x / 10;

        if x == 0 {
            break
        }
    }


    let mut res: i32 = 0;
    let mut p = 1;

    for digit in vec.iter().rev()
    {
        let maxp = std::i32::MAX / p;
        if *digit > maxp {
            return 0;
        }

        if p*digit > std::i32::MAX - res {
            return 0;
        }

        res += p * digit;

        if 10 < maxp {
            p = 10 * p;
        }
    }

    if is_negative == true {
        res = -1 * res;
    }

    return res;    
}
