class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_dict = {}
        for idx, num in enumerate(nums):
            if target-num in index_dict:
                return [index_dict[target-num], idx]
            else:
                index_dict[num] = idx
        return []