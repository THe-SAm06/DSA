class Solution {
    int recur(int idx,vector<int>& nums,vector<int>& dp){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx] + recur(idx+2,nums,dp);
        int not_take = recur(idx+1,nums,dp);

        return dp[idx] = max(take,not_take);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return recur(0,nums,dp);
    }
};