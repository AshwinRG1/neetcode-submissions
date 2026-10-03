class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        seen = set(nums)
        for i, num in enumerate(nums):
            if num-1 not in seen:
                curr = num
                temp = 0

                while curr in seen:
                    curr += 1
                    temp += 1
                    res = max(res, temp)
        return res