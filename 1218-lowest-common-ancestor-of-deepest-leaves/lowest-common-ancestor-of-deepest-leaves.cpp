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
    unordered_map<TreeNode*,int> mp;
    int maxd = 0;
    void depth(TreeNode* root,int level){
        if(!root) return;
        depth(root->left,level+1);
        maxd = max(maxd,level);
        mp[root] = level;
        depth(root->right,level+1);
    }
    TreeNode* helper(TreeNode* root){
        if(!root) return nullptr;
        if(mp[root] == maxd) return root;
        TreeNode* left = helper(root->left);
        TreeNode* right = helper(root->right);
        if(left && right) return root;
        if(left) return left;
        return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root,0);
        return helper(root);
    }
};