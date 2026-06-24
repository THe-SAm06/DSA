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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long ans = 0;
        while(!q.empty()){
            long long s = q.size();
            ans = max(ans,q.back().second - q.front().second+1);
            long long minidx = q.front().second;
            while(s--){
                if(q.front().first->left){
                    if(q.front().second != 0){
                        q.push({q.front().first->left,2*(q.front().second-minidx)+1});
                    }
                    else q.push({q.front().first->left,2*(q.front().second)+1});
                }
                if(q.front().first->right){
                    if(q.front().second != 0){
                        q.push({q.front().first->right,2*(q.front().second-minidx)+2});
                    }
                    else q.push({q.front().first->right,2*(q.front().second)+2});
                }
                q.pop();
            }
        }
        return (int)ans;
    }
};