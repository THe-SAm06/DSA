class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;

        vector<pair<int,int>> dir = {{0,-1},{-1,0}};

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!i && !j) continue;
                int total = 0;
                for(auto &[x,y]: dir){
                    int ni = i+x;
                    int nj = j+y;
                    if(ni>=0 && nj>=0 && dp[ni][nj]){
                        total += dp[ni][nj];
                    }
                }
                dp[i][j] = total;
            }
        }
        return dp[m-1][n-1];
    }
};