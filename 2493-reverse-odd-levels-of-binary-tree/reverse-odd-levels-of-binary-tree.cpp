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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int s = q.size();
            if(!(level&1)){
                vector<TreeNode*> oddlevel;
                while(s--){
                    TreeNode* curr = q.front();
                    q.pop();
                    if(curr->left){
                        q.push(curr->left);
                        oddlevel.push_back(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                        oddlevel.push_back(curr->right);
                    }
                }
                int i = 0, j = oddlevel.size()-1;
                while(i<j){
                    swap(oddlevel[i]->val,oddlevel[j]->val);
                    i++;
                    j--;
                }
            }
            else{
                while(s--){
                    TreeNode* curr = q.front();
                    q.pop();
                    if(curr->left){
                        q.push(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }
                }
            }
            level++;
        }
        return root;
    }
};