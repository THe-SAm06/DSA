class Solution {
public:
    bool dfs(int i,int j,pair<int,int> par,vector<vector<char>>& grid,vector<vector<bool>> &vis,vector<pair<int,int>> &dir){
        vis[i][j] = true;
        for(auto [x,y]: dir){
            
            int ni = i+x;
            int nj = j+y;

            if(ni<0 || nj<0 || ni>=grid.size() || nj>=grid[0].size() || grid[ni][nj]!=grid[i][j]) continue;

            if(vis[ni][nj] && make_pair(ni,nj)!=par) return true;
            if(!vis[ni][nj]){
                if(dfs(ni,nj,{i,j},grid,vis,dir)) return true;
            } 
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {

        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(!vis[i][j]){
                    if(dfs(i,j,{-1,-1},grid,vis,dir)) return true;
                }
            }
        }
        return false;
    }
};