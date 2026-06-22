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
    void fun(TreeNode* root,int col,int row,map<int,map<int,multiset<int>>>& mp){
        if(!root) return;
        mp[col][row].insert(root->val);
        if(root->left) fun(root->left,col-1,row+1,mp);
        if(root->right) fun(root->right,col+1,row+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        fun(root,0,0,mp);
        vector<vector<int>> ans;
        for(auto [col,row_map]: mp){
            vector<int> curr;
            for(auto [row,set]: row_map){
                for(int a:set) curr.push_back(a);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};