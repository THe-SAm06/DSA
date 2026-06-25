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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int i,int l, int r){
        if(l>r) return nullptr;
        int idx = find(inorder,l,r,preorder[i]);
        if (idx == -1) return nullptr;
        TreeNode* root = new TreeNode(inorder[idx]);
        TreeNode* left = helper(preorder,inorder,i+1,l,idx-1);
        TreeNode* right = helper(preorder,inorder,i+idx-l+1,idx+1,r);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++) mp[inorder[i]] = i;
        return helper(preorder,inorder,0,0,preorder.size()-1);
    }
};