class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int mins  = 0;
        int fresh_fruits = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1) fresh_fruits++;
            }
        }
        if(fresh_fruits==0) return 0;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int s = q.size();
            bool has_neighbour = false;
            while(s--){
                auto [i,j] = q.front();
                q.pop();
                for(auto [x,y]:dir){
                    int next_i = i+x;
                    int next_j = j+y;
                    if(next_i>=0 && next_i<grid.size() && next_j>=0 && next_j<grid[0].size() && grid[next_i][next_j]==1){
                        has_neighbour = true;
                        grid[next_i][next_j] = 2;
                        q.push({next_i,next_j});
                        fresh_fruits--;
                    }
                }
            }
            if(has_neighbour) mins++;
        }
        if(fresh_fruits>0) return -1;
        return mins;
    }
};