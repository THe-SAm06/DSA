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
    unordered_map<TreeNode*,TreeNode*> parent;
    void find_parent(TreeNode* root,TreeNode*& node,int start){
        if(!root) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        if(root->val == start) node = root;
        find_parent(root->left,node,start);
        find_parent(root->right,node,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* startnode;
        find_parent(root,startnode,start);
        queue<TreeNode*> q;
        unordered_set<int> vis;
        q.push(startnode);
        vis.insert(start);
        int mins = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                if(q.front()->left && (vis.find(q.front()->left->val)==vis.end())){
                    q.push(q.front()->left);
                    vis.insert(q.front()->left->val);
                }
                if(q.front()->right && (vis.find(q.front()->right->val)==vis.end())){
                    q.push(q.front()->right);
                    vis.insert(q.front()->right->val);
                }
                if(parent[q.front()] && (vis.find(parent[q.front()]->val)==vis.end())){
                    q.push(parent[q.front()]);
                    vis.insert(parent[q.front()]->val);
                }
                q.pop();
            }
            mins++;
        }
        return mins-1;
    }
};