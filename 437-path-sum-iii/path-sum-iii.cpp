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
    void dfs(TreeNode* root,int t,unordered_map<long long,long long>& mp,int& total,long long& sum){
        if(!root) return;
        sum += root->val;
        if(mp.find(sum-t) != mp.end()){
            total += mp[sum-t];
        }
        mp[sum]++;
        dfs(root->left,t,mp,total,sum);
        dfs(root->right,t,mp,total,sum);
        mp[sum]--;
        sum -= root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,long long> mp;
        mp[0]++;
        int total = 0;
        long long sum = 0;
        dfs(root,targetSum,mp,total,sum);
        return total;
    }
};