class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        i = 0
        maxP = 0

        for j in range(len(prices)):
            maxP = max(maxP, prices[j] - prices[i])

            while (prices[j] < prices[i]):
                i += 1


        return maxP