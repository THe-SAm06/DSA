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
    void dfs(TreeNode* left,TreeNode* right,int d){
        if(!left) return;
        if(d&1){
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }
        dfs(left->left,right->right,d+1);
        dfs(left->right,right->left,d+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root ||!root->left) return root;
        dfs(root->left,root->right,1);
        return root;
    }
};