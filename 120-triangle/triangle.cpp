class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp;

        for (auto &vec : triangle) {
            dp.push_back(vector<int>(vec.size(), -1));
        }

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {

            for (int j = 0; j < triangle[i].size(); j++) {

                int prev1 = INT_MAX;
                int prev2 = INT_MAX;

                if (j < triangle[i - 1].size())
                    prev1 = dp[i - 1][j];

                if (j > 0)
                    prev2 = dp[i - 1][j - 1];

                dp[i][j] = min(prev1, prev2) + triangle[i][j];
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < triangle[n - 1].size(); i++) {
            ans = min(ans, dp[n - 1][i]);
        }

        return ans;
    }
};