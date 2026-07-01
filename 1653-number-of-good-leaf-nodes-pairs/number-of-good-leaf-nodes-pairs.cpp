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
    int count = 0;
    vector<int> helper(TreeNode* root,int d){
        if(!root) return {};
        if(!root->left && !root->right) return {1};
        vector<int> left = helper(root->left,d);
        vector<int> right = helper(root->right,d);
        for(int a:left){
            for(int b:right){
                if((a+b)<=d) count++;
            }
        }
        for (auto& x : left) x += 1;
        for (auto& x : right) x += 1;
        for(int a:right) left.push_back(a);
        return left;
    }
    int countPairs(TreeNode* root, int distance) {
        helper(root,distance);
        return count;
    }
};