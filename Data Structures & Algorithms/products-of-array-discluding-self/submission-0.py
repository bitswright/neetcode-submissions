class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefixProduct = [1] * len(nums)
        product = 1
        for i in range(len(nums)):
            prefixProduct[i] = product
            product *= nums[i]
        productsExceptSelf = [1] * len(nums)
        product = 1
        for i in range(len(nums)-1, -1, -1):
            productsExceptSelf[i] = product * prefixProduct[i]
            product *= nums[i]
        return productsExceptSelf
