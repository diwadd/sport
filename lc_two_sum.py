class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sorted_nums = sorted(nums)

        left = 0
        right = len(sorted_nums) - 1
        sorted_indexes = []

        while (left < right):
            if sorted_nums[left] + sorted_nums[right] == target:
                sorted_indexes = [left, right]
                break
            if sorted_nums[left] + sorted_nums[right] > target:
                right -= 1
                continue
            if sorted_nums[left] + sorted_nums[right] < target:
                left += 1
                continue
        
        res_left = 0
        res_right = 0

        for i in range(0, len(nums)):
            if sorted_nums[sorted_indexes[0]] == nums[i]:
                res_left = i
                break

        for i in range(0, len(nums)):
            if sorted_nums[sorted_indexes[1]] == nums[i] and i != res_left:
                res_right = i
                break
        
        return [res_left, res_right]
