class Solution {
    int dp[50][50][50][50];
    int rec(int r1,int r2,int c1,int c2,vector<vector<int>>& grid){
        if(r1<0 || r2<0 || c1<0 || c2<0 || r1>=grid.size() || r2>=grid.size() || c1>=grid[0].size() || c2>= grid[0].size() || grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e8;

        if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];

        int curr_cherries = 0;

        if(r1==r2 && c1==c2){
            if(r1==grid.size()-1 && c1==grid[0].size()-1){
                return dp[r1][c1][r2][c2] = grid[r1][c1];
            }
            else{
                curr_cherries += grid[r1][c1];
            }
        }
        else{
            curr_cherries += grid[r1][c1] + grid[r2][c2];
        }

        int p1 = rec(r1+1,r2+1,c1,c2,grid);
        int p2 = rec(r1,r2,c1+1,c2+1,grid);
        int p3 = rec(r1+1,r2,c1,c2+1,grid);
        int p4 = rec(r1,r2+1,c1+1,c2,grid);

        return dp[r1][c1][r2][c2] = max({p1,p2,p3,p4}) + curr_cherries;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return max(0,rec(0,0,0,0,grid));
    }
};