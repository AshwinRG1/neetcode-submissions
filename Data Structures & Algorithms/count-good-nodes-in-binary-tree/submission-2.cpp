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
    int goodNodes(TreeNode* root) {
        if (!root){
            return 1;
        }
        if (root->left && root->right){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            if (root->val < left->val && root->val < right->val){
                return 1 + goodNodes(left) + goodNodes(right);
            } else {
                return goodNodes(left) + goodNodes(right);
            }
        }
        else if (root->left){
            TreeNode* left = root->left;
            if (root->val < left->val){
                return 1 + goodNodes(left);
            } else {
                return goodNodes(left);
            }
        }
        else if (root->right){
            TreeNode* right = root->right;
            if (root->val < right->val){
                return 1 + goodNodes(right);
            } else {
                return goodNodes(right);
            }
        } else {
            return 0;
        }
    }
};
