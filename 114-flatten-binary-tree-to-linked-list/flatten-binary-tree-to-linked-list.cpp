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
 TreeNode* helper(TreeNode* root){
    if(!root) return nullptr;

    TreeNode* leftHead = root->left;
    TreeNode* rightHead = root->right;

    TreeNode* leftTail = helper(leftHead);
    TreeNode* rightTail = helper(rightHead);

    if(leftHead){
        root->right = leftHead;
        root->left = nullptr;
        leftTail->right = rightHead;
    }else{
        root->right = rightHead;
        root->left = nullptr;
    }

    if(rightTail) return rightTail;
    if(leftTail) return leftTail;
    return root;
}
    void flatten(TreeNode* root) {
        helper(root);
    }
};