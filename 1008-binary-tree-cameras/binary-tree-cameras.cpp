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
    int dfs(TreeNode* root,int& count){
        if(!root) return 2;

        int l = dfs(root->left,count);
        int r = dfs(root->right,count);

        if(l==0 || r==0){
            count++;
            return 1;  //has_camera
        }
        if(l== 1 || r==1) return 2;  //this node is covered by one(or both) the child nodes;
        return 0;  //both child nodes are covered cameras of their child so this node need camera;
    }
    int minCameraCover(TreeNode* root) {
        int count = 0;
        if(dfs(root,count) == 0) count++;  //both the child of root are covered from their child so the root must have a camera
        return count;
    }
};