class Solution {
public:
    int solve(vector<int>& coins, int amount, int sum, int ind, vector<vector<int>>& dp){

        if(sum == amount)
            return 0;
        if(sum > amount || ind < 0)
            return 1e9;
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        int take = 1 + solve(coins, amount, sum + coins[ind], ind, dp);
        int skip = solve(coins, amount, sum, ind - 1, dp);
        return dp[ind][sum] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, 0, n-1, dp);
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};