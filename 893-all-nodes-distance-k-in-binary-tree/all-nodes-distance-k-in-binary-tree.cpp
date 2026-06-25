/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void find_parent(TreeNode* root){
        if(!root) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        find_parent(root->left);
        find_parent(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        find_parent(root);
        queue<TreeNode*> q;
        unordered_set<int> vis;
        q.push(target);
        vis.insert(target->val);
        while(!q.empty()){
            if(k==0) break;
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
            k--;
        }
        if(q.empty()) return {};
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};