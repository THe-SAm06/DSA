class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minCost(vector<vector<int>>& grid) {

        unordered_map<int,pair<int,int>> mp = {
            {1,{0,1}}, {2,{0,-1}}, {3,{1,0}}, {4,{-1,0}}
        };

        int m = grid.size();
        int n = grid[0].size();

        priority_queue<p,vector<p>,greater<p>> pq;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto [cost,idx] = pq.top();
            auto [i,j] = idx;
            pq.pop();
            vis[i][j] = true;

            cout<<"popped: "<<i<<" "<<j<<" "<<cost<<'\n';

            if(dist[i][j]>cost) continue;
            if(i == m-1 && j == n-1) return cost;

            for(auto &[x,y] : dir){
                int ni = i+x;
                int nj = j+y;
                if(ni>=0 && nj>=0 && ni<m && nj<n && !vis[ni][nj]){
                    cout<<ni<<" "<<nj<<" ";
                    if(make_pair(x,y) == mp[grid[i][j]]){
                        if(dist[ni][nj] > cost){
                            cout<<cost<<'\n';
                            dist[ni][nj] = cost;
                            pq.push({cost,{ni,nj}});
                        }
                    }
                    else{
                        if(dist[ni][nj] > cost+1){
                            cout<<cost+1<<'\n';
                            dist[ni][nj] = cost+1;
                            pq.push({cost+1,{ni,nj}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};