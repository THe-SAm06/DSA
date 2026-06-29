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
private:
    struct info{
        int size;
        int sum;
    };
public:
    info dfs(TreeNode* root,int& count){
        if(!root) return {0,0};
        info left = dfs(root->left,count);
        info right = dfs(root->right,count);
        int tsum = root->val + left.sum + right.sum;
        int tsize = 1 + left.size + right.size;
        if(root->val == (tsum)/(tsize)) count++;
        return {tsize,tsum};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root,count);
        return count;
    }
};