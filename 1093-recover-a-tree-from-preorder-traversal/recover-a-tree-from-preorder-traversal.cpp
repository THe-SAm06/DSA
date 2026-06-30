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
    TreeNode* helper(string s,int& idx,int depth){
        if(idx>=s.size()) return nullptr;
        int j = idx;
        while(j<s.size() && s[j]=='-') j++;
        if(j-idx<depth) return nullptr;
        idx = j;
        int num =0;
        while(idx<s.size() && isdigit(s[idx])){
            num = num*10 + (s[idx]-'0');
            idx++;
        }
        TreeNode* root = new TreeNode(num);
        root->left = helper(s,idx,depth+1);
        root->right = helper(s,idx,depth+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0;
        return helper(traversal,idx,0);
    }
};