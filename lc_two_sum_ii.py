class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:

        left = 0
        right = len(numbers) - 1

        while (left < right):
            if numbers[left] + numbers[right] == target:
                return [left + 1, right + 1]
                break
            if numbers[left] + numbers[right] > target:
                right -= 1
                continue
            else:
                left += 1
                continue
    
        return [0, 0]
