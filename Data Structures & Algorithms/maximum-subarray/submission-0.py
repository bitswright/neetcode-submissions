class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        l, r = 0, 0
        subSum, maxSubSum = 0, float('-inf')
        for r in range(len(nums)):
            subSum += nums[r]
            maxSubSum = max(maxSubSum, subSum)
            while subSum < 0:
                subSum -= nums[l]
                l += 1
        return maxSubSum