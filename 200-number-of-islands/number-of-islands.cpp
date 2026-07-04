class Solution {
public:
    vector<vector<int>> dir ={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>> &visited){
        visited[i][j] = true;
        for(auto vec : dir){
            int next_i = i+vec[0];
            int next_j = j+vec[1];
            if(next_i<grid.size() && next_j<grid[0].size()){
                if(!visited[next_i][next_j] && grid[next_i][next_j]=='1') dfs(next_i,next_j,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0; j<grid[i].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    ans++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return ans;
    }
};