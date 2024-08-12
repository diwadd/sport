class Solution:
    def rotate(self, nums: List[int], k: int) -> None:

        n = len(nums)

        if k > n:
            k =  k % n

        rn = [nums[i] for i in range(n)]

        for i in range(0, k):
            nums[k - i - 1] = rn[n - i - 1]

        for i in range(0, n - k):
            nums[i + k] = rn[i]

        nums = rn
