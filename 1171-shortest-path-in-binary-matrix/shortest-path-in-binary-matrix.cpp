class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});

        int dist = 1;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front();
                q.pop();

                if(i==n-1 && j==n-1) return dist;

                for(int x = -1;x<=1;x++){
                    for(int y = -1;y<=1;y++){
                        if(!x && !y) continue;

                        int ni = i+x;
                        int nj = j+y;

                        if(ni==n-1 && nj==n-1) return dist+1;

                        if(ni>=0 and nj>=0 && ni<n && nj<n && !grid[ni][nj]){
                            q.push({ni,nj});
                            grid[ni][nj] = 1;
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};