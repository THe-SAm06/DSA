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
    TreeNode* LCA(TreeNode* root,int x,int y){
        if(!root) return nullptr;
        if(root->val == x || root->val==y) return root;
        TreeNode* left = LCA(root->left,x,y);
        TreeNode* right = LCA(root->right,x,y);
        if(left&&right) return root;
        if(left) return left;
        return right;
    }
    bool findpath(TreeNode* root,int x,string& ans){
        if(!root) return false;
        if(root->val == x) return true;
        ans.push_back('L');
        if(findpath(root->left,x,ans)) return true;
        ans.pop_back();
        ans.push_back('R');
        if(findpath(root->right,x,ans)) return true;
        ans.pop_back();
        return false;

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s1, s2;
        TreeNode* lca = LCA(root,startValue,destValue);
        findpath(lca,startValue,s1);
        findpath(lca,destValue,s2);
        return string(s1.size(),'U') + s2;
    }
};