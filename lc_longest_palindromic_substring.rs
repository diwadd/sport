impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        
    if s.len() == 0
    {
        return String::new();
    }

    let s_with_sticks: Vec<char> = s.chars().collect();

    let n: usize = s_with_sticks.len();
    let mut max_left = 0;
    let mut max_right = 0;
    for i in 0..n {

        let mut left: usize = i;
        let mut right: usize = i;

        while right + 1 < n && s_with_sticks[right + 1] == s_with_sticks[left]
        {
            right += 1;
        }

        while right + 1 < n && left > 0 && s_with_sticks[right + 1] == s_with_sticks[left - 1]
        {
            right += 1;
            left -= 1;  
        }
  
        if right - left > max_right - max_left
        {
            max_left = left;
            max_right = right;
        }
    }

    return s_with_sticks[max_left..max_right + 1].iter().collect()

    }
}
