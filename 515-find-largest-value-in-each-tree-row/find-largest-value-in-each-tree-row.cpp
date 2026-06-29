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
    void dfs(TreeNode* root,vector<int>& arr,int depth){
        if(!root) return;
        if(depth == arr.size()) arr.push_back(root->val);
        else arr[depth] = max(arr[depth],root->val);
        dfs(root->left,arr,depth+1);
        dfs(root->right,arr,depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        dfs(root,result,0);
        return result;
    }
};