class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        vector<vector<int>> dp(n,vector<int>(2,-1));

        dp[0][0] = 0;
        dp[0][1] = nums[0];

        for(int i = 1;i<n-1;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = nums[i] + dp[i-1][0];
        }

        int m1 =max(dp[n-2][0],dp[n-2][1]);

        dp[1][0] = 0;
        dp[1][1] = nums[1];

        for(int i = 2;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = nums[i] + dp[i-1][0];
        }

        int m2 = max(dp[n-1][0],dp[n-1][1]);

        return max(m1,m2);
    }
};