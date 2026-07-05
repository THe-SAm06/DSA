class Solution {
private:
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=2;
        for(auto [x,y]: dir){
            int ii = i+x;
            int jj = j+y;
            if(ii>=0 && jj>=0 && ii<grid.size() && jj<grid[0].size() && grid[ii][jj]==1){
                dfs(ii,jj,grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0;i<m;i++){
            if(grid[i][0]==1) dfs(i,0,grid);
            if(grid[i][n-1]==1) dfs(i,n-1,grid);
        }
        for(int j =0;j<n;j++){
            if(grid[0][j]==1) dfs(0,j,grid);
            if(grid[m-1][j]==1) dfs(m-1,j,grid);
        }
        int count = 0;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};