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
    long long prev = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool left = isValidBST(root->left);
        if(root->val<=prev) return false;
        else prev = root->val;
        bool right = isValidBST(root->right);
        if(!left || !right) return false;
        return true;
    }
};