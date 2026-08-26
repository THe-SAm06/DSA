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
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2;i<nums.size();i++){
            dp[i] = max(dp[i-1] , nums[i] + dp[i-2]);
        }

        return dp.back();
    }
};