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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int levelsum = root->val;
        int lastlevelsum;
        while(!q.empty()){
            int s = q.size();
            lastlevelsum = levelsum;
            levelsum = 0;
            while(s--){
                int sibsum = 0;
                TreeNode* curr = q.front();
                q.pop();
                curr->val = lastlevelsum - curr->val;
                if(curr->left){
                    sibsum += curr->left->val;
                }
                if(curr->right){
                    sibsum += curr->right->val;
                }
                if(curr->left) curr->left->val = sibsum;
                if(curr->right) curr->right->val = sibsum;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                levelsum += sibsum;
            }
        }
        return root;
    }
};