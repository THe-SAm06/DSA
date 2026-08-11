class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0]) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
    
        vector<pair<int,int>> dir = {{0,-1},{-1,0}};
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!i && !j) continue;
                if(obstacleGrid[i][j]) dp[i][j] = 0;
                else{
                    int total = 0;
                    for(auto &[x,y]: dir){
                        int ni = i+x;
                        int nj = j+y;
                        if(ni>=0 && nj>=0 && ni<m && nj<n){
                            total += dp[ni][nj];
                        }
                    }
                    dp[i][j] = total;
                }
            }
        }
        return dp[m-1][n-1];
    }
};