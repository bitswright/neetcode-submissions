class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        current_max = nums[0]
        current_min = nums[0]

        max_product = nums[0]

        product = 1

        for num in nums[1:]:
            prev_max = current_max
            prev_min = current_min

            current_max = max(num, prev_max*num, prev_min*num)
            current_min = min(num, prev_max*num, prev_min*num)

            max_product = max(max_product, current_max)
        
        return max_product