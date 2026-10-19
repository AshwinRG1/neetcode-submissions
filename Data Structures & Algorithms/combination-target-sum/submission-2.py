class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        path = []
        path_sum = 0
        def backtrack(index,path, path_sum):
            if path_sum == target:
                res.append(path.copy())
                return
            if index == len(nums) or path_sum > target:
                return
            path.append(nums[index])
            path_sum += nums[index]
            backtrack(index, path,path_sum)
            path.pop()
            path_sum -= nums[index]
            backtrack(index+1, path, path_sum)
        backtrack(0,path,path_sum)
        return res



        