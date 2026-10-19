class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        path = []
        def backtrack(index, path):
            path = res.append(nums[index])
            backtrack(index+1, path)
            path.pop()
            backtrack(index+1, path)
        return res
