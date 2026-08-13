class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,INT_MAX)));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<3;j++){
                dp[0][i][j] = matrix[0][i];
            }
        }
        vector<pair<int,int>> dir = {{-1,-1},{-1,0},{-1,1}};
        for(int i = 1;i<m;i++){
            for(int j = 0;j<n;j++){
                for(int k = 0;k<3;k++){
                    int ni = i+dir[k].first;
                    int nj = j+dir[k].second;
                    if(ni>=0 && nj>=0 && ni<m && nj<n){
                        dp[i][j][k] = matrix[i][j] + min({dp[ni][nj][0],dp[ni][nj][1],dp[ni][nj][2]});
                    }
                }
            }
        }
        int mn = INT_MAX;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<3;j++){
                mn = min(mn,dp[m-1][i][j]);
            }
        }
        return mn;
    }
};