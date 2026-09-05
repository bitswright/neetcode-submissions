class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_product = float('-inf')
        prefix = 1
        for num in nums:
            prefix *= num
            max_product = max(max_product, prefix)
            if prefix == 0:
                prefix = 1
            
        suffix = 1
        for i in range(len(nums)-1, -1, -1):
            suffix *= nums[i]
            max_product = max(max_product, suffix)
            if suffix == 0:
                suffix = 1

        return max_product
