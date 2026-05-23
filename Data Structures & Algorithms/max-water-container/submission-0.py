class Solution:
    def maxArea(self, heights: List[int]) -> int:
        res = 0
        l = 0
        r = len(heights) - 1

        while r > l:
            temp = (r - l) * min(heights[l], heights[r])
            if temp > res:
                res = temp
            if heights[l] > heights[r]:
                r-=1
            else:
                l+=1


        return res