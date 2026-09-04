class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minSoFar = float('inf')
        maxProfit = 0
        for price in prices:
            minSoFar = price if price < minSoFar else minSoFar
            maxProfit = price - minSoFar if price - minSoFar > maxProfit else maxProfit
        return maxProfit