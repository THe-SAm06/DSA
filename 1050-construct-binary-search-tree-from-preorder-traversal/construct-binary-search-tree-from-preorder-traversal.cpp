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
    TreeNode* helper(vector<int>& preorder,int l,int r){
        if(l>r) return nullptr;
        TreeNode* root = new TreeNode(preorder[l]);
        auto it = upper_bound(preorder.begin()+l, preorder.begin()+r+1, preorder[l]);
        int index = it - preorder.begin();
        root->left = helper(preorder,l+1,index-1);
        root->right = helper(preorder,index,r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size()-1);
    }
};