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
    int maxtime = INT_MIN;
    int dfs(TreeNode* root, int start) {
        if(!root) return 0;
        int left = dfs(root->left,start);
        int right = dfs(root->right,start);
        if(root->val == start){
            maxtime = max(maxtime,(max(left,right)));
            return -1;
        }
        if(left<0){
            maxtime = max(maxtime,abs(left)+right);
            return left-1;
        }
        if(right<0){
            maxtime = max(maxtime,abs(right)+left);
            return right-1;
        }
        return max(left,right)+1;
    }
    int amountOfTime(TreeNode* root, int start){
        dfs(root,start);
        return maxtime;
    }
};