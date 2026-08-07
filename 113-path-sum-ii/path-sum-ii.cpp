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
    void dfs(TreeNode* root,int t,vector<int> &curr,vector<vector<int>> &ans,int &sum){
        if(!root) return;
        if(!root->left && !root->right){
            curr.push_back(root->val);
            sum += root->val;
            if(sum == t){
                ans.push_back(curr);
            }
            curr.pop_back();
            sum -= root->val;
        }
        sum += root->val;
        curr.push_back(root->val);
        dfs(root->left,t,curr,ans,sum);
        dfs(root->right,t,curr,ans,sum);
        sum -= root->val;
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        int sum = 0;
        dfs(root,targetSum,curr,ans,sum);
        return ans;
    }
};