/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root){
            return true;
        }
        vector<int> traversal;
        dfs(root, traversal);

        for (int i = 1; i < traversal.size(); i++){
            if (traversal[i-1] >= traversal[i]){
                return false;
            }
        }
        
        return true;
    }

    void dfs(TreeNode* root, vector<int>& traversal){
    if (root == nullptr) return;

    dfs(root->left, traversal);        
    traversal.push_back(root->val);          
    dfs(root->right, traversal);

    }
};
