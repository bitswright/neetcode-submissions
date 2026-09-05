class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        productsExceptSelf = [1] * len(nums)
        prefix = 1
        for i in range(len(nums)):
            productsExceptSelf[i] = prefix
            prefix *= nums[i]
        suffix = 1
        for i in range(len(nums)-1, -1, -1):
            productsExceptSelf[i] *= suffix
            suffix *= nums[i]
        return productsExceptSelf
