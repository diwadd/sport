

fn get_combination(
    res: &mut Vec<Vec<i32>>,
    index: usize,
    candidates: &Vec<i32>,
    current_combination: &mut Vec<i32>,
    total: i32,
    target: i32)
{
    if index >= candidates.len()
    {
        return;
    }

    if total > target
    {
        return;
    }

    if total == target
    {
        res.push(current_combination.to_vec());
        return;
    }

    current_combination.push(candidates[index]);
    get_combination(res, index, candidates, current_combination, total + candidates[index], target);
    current_combination.pop();
    get_combination(res, index+1, candidates, current_combination, total, target);

    return

}


fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {

    let mut res: Vec<Vec<i32>> = Vec::new();
    let mut current_combination: Vec<i32> = Vec::new();

    get_combination(&mut res, 0, &candidates, &mut current_combination, 0, target);

    return res
}


fn main() {

    print!("Works\n");

    let candidates = vec![2,3,6,7];
    let target = 8;

    let res = combination_sum(candidates, target);

    for r in &res {
        print!("Element\n");
        for x in r {
            print!("{x} ");
        }
        print!("\n")
    }

}
