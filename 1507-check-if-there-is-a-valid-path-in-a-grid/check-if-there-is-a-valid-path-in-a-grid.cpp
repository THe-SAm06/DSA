class Solution {
public:
    bool dfs(int x,int y,vector<vector<int>>& grid,vector<vector<bool>> &vis,unordered_map<int,vector<pair<int,int>>> &dir){

        if(x == grid.size()-1 && y == grid[0].size()-1) return true;
        vis[x][y] = true;

        for(auto p: dir[grid[x][y]]){

            int i = x + p.first;
            int j = y + p.second;

            if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && !vis[i][j]){
               for(auto p_ :dir[grid[i][j]]){
                int ii = i+p_.first;
                int jj = j+p_.second;
                if(ii == x && jj==y){
                    if(dfs(i,j,grid,vis,dir)) return true;
                }
               }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int,vector<pair<int,int>>> dir;
        dir[1] = {{0,1},{0,-1}};
        dir[2] = {{1,0},{-1,0}};
        dir[3] = {{0,-1},{1,0}};
        dir[4] = {{0,1},{1,0}};
        dir[5] = {{-1,0},{0,-1}};
        dir[6] = {{-1,0},{0,1}};

        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));

        return dfs(0,0,grid,vis,dir);
    }
};