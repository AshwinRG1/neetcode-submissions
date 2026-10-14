# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.good = 0
        self.dfs(root, root.val)
        return self.good

    
    def dfs(self, node: TreeNode, m: int):
        if not node:
            return

        if node.val >= m:
            m = node.val
            self.good += 1
        
        self.dfs(node.left, m)
        self.dfs(node.right, m)

        

