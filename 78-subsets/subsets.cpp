class Solution {
public:
    void backtrack(int n,int i,vector<vector<int>> &sub,vector<int> &v,vector<int> &nums){
        if(i==n){
            sub.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        backtrack(n,i+1,sub,v,nums);
        v.pop_back();
        backtrack(n,i+1,sub,v,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sub;
        vector<int> v;
        backtrack(nums.size(),0,sub,v,nums);
        return sub;
    }
};