class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        nums.sort()
        # print(nums)
        res = []
        for i in range(0, len(nums) - 2):

            if i > 0 and nums[i] == nums[i-1]:
                continue

            j = i + 1
            k = len(nums) - 1
            
            while j < k:
                # print(f"{i} {j} {k}")
                s = nums[i] + nums[j] + nums[k]
                if s == 0:
                    res.append([nums[i], nums[j], nums[k]])
                    while j+1 < len(nums) and nums[j] == nums[j+1]:
                        j += 1
                    while k-1 > 0 and nums[k] == nums[k-1]:
                        k -= 1
                    j += 1
                    k -= 1
                elif s > 0:
                    k -= 1
                elif s < 0:
                    j += 1

        return res
