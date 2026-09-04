class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minSoFar = prices[0]
        maxProfit = 0
        for price in prices[1:]:
            minSoFar = min(price, minSoFar)
            maxProfit = max(price - minSoFar, maxProfit)
        return maxProfit