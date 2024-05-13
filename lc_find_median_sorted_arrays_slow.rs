impl Solution {
    fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {

        let mut sorted_nums: Vec<i32> = Vec::new();

        let n1 = nums1.len();
        let n2 = nums2.len();

        let mut index1 = 0;
        let mut index2 = 0;

        while index1 < n1 && index2 < n2 {

            if nums1[index1] <= nums2[index2] {
                sorted_nums.push(nums1[index1]);
                index1 += 1;
                continue;
            }
            if nums1[index1] > nums2[index2] {
                sorted_nums.push(nums2[index2]);
                index2 += 1;
                continue;
            }
        }

        while index1 < n1 {
            sorted_nums.push(nums1[index1]);
            index1 += 1;
        }

        while index2 < n2 {
            sorted_nums.push(nums2[index2]);
            index2 += 1;
        }

        if sorted_nums.len() % 2 == 0 {
            return (sorted_nums[sorted_nums.len() / 2 as usize] +
                sorted_nums[sorted_nums.len() / 2 as usize - 1]) as f64 / 2.0 as f64;
        }
        else
        {
            return sorted_nums[sorted_nums.len() / 2 as usize] as f64;
        }
    }
}
