class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        res = 0
        def canEat(speed) -> bool:
            hours = 0
            for num in piles:
                hours += math.ceil(num/speed)
            if hours > h:
                return False
            return True
        
        left, right = 1, max(piles)
        
        while left <= right:
            mid = (left + right) // 2

            if canEat(mid):
                res = mid
                right = mid - 1
            else:
                left = mid + 1
        return res