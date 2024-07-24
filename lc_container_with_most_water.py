import math

class Solution:
    def maxArea(self, height: List[int]) -> int:

        left = 0
        right = len(height) - 1

        volume = -math.inf
        while left < right:
            if left >= len(height) or right < 0:
                break

            h = min(height[left], height[right])

            v = h * (right - left)
            if v > volume:
                volume = v

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        
        return volume
