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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> pq;
        vector<vector<int>> ans;
        pq.push(root);
        bool LtoR = 1;
        while(!pq.empty()){
            vector<int> curr;
            int c = pq.size();
            while(c--){
                curr.push_back(pq.front()->val);
                if(pq.front()->left) pq.push(pq.front()->left);
                if(pq.front()->right) pq.push(pq.front()->right);
                pq.pop();
            }
            if(LtoR){
                ans.push_back(curr);
                LtoR = false;
            }
            else{
                reverse(curr.begin(),curr.end());
                ans.push_back(curr);
                LtoR = true;
            }
        }
        return ans;
    }
};