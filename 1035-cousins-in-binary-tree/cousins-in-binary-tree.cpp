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
    TreeNode* xpar = nullptr, *ypar = nullptr;
    int xd, yd;
    void dfs(TreeNode* root,TreeNode* par,int depth,int x,int y){
        if(!root) return;
        if(root->val == x){
            xd = depth;
            xpar = par;
        }
        if(root->val == y){
            yd = depth;
            ypar = par;
        }
        dfs(root->left,root,depth+1,x,y);
        dfs(root->right,root,depth+1,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,nullptr,0,x,y);
        // cout<<xpar->val<<" "<<xd<<"\n";
        // cout<<ypar->val<<" "<<yd<<"\n";
        return (xd==yd) && (ypar!=xpar);
    }
};