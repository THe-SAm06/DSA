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
unordered_map<int,int> mp;
    int find(vector<int>& inorder,int l ,int r,int k){
        if(mp[k]>=l && mp[k]<=r) return mp[k];
        return -1;
    }
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder,int i,int l, int r){
        if(l>r) return nullptr;
        int idx = find(inorder,l,r,postorder[i]);
        if (idx == -1) return nullptr;
        TreeNode* root = new TreeNode(inorder[idx]);
        TreeNode* left = helper(postorder,inorder,i-(r-idx+1),l,idx-1);
        TreeNode* right = helper(postorder,inorder,i-1,idx+1,r);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0;i<inorder.size();i++) mp[inorder[i]] = i;
        return helper(postorder,inorder,postorder.size()-1,0,postorder.size()-1);
    }
};