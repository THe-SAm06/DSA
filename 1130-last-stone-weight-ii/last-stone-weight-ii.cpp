class Solution {
    int rec(int idx, vector<int>& stones, int total, int sum,
            vector<vector<int>>& dp) {

        if (idx == stones.size()) {
            return abs(total - 2 * sum);
        }

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        int take = rec(idx + 1, stones, total,
                       sum + stones[idx], dp);

        int skip = rec(idx + 1, stones, total,
                       sum, dp);

        return dp[idx][sum] = min(take, skip);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;

        for (int x : stones)
            total += x;

        vector<vector<int>> dp(
            stones.size(),
            vector<int>(total + 1, -1)
        );

        return rec(0, stones, total, 0, dp);
    }
};