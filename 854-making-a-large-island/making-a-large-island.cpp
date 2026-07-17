class DisjointSet{
    private:
        vector<int> rank,par,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            par.resize(n+1,0);
            size.resize(n+1,1);
            for(int i = 0;i<n;i++) par[i] = i;
        }
        int findpar(int node){
            if(node == par[node]) return node;
            return par[node] = findpar(par[node]);
        }
        void ubr(int u,int v){
            
            int p_u = findpar(u);
            int p_v = findpar(v);
            
            if(p_u == p_v) return;
            
            if(rank[p_u]>rank[p_v]){
                par[p_v] = p_u;
            }
            else if(rank[p_v]>rank[p_u]){
                par[p_u] = p_v;
            }
            else{
                par[p_v] = p_u;
                rank[p_u]++;
            }
        }
        
        void ubs(int u,int v){
            int p_u = findpar(u);
            int p_v = findpar(v);
            
            if(p_u == p_v) return;
            
            if(size[p_u]>=size[p_v]){
                par[p_v] = p_u;
                size[p_u] += size[p_v];
            }
            else if(size[p_v]>size[p_u]){
                par[p_u] = p_v;
                size[p_v] += size[p_u];
            }
        }
        const int getsize(int u) const{
            return size[u];
        }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DisjointSet ds(n*m);
        int mx = 1;
        int i = 0;

        vector<pair<int,int>> dir = {{0,1},{1,0}};
        for(auto vec: grid){
            for(int j = 0;j<m;j++){
                if(vec[j]){
                    for(auto &[x,y]: dir){
                        int ii = i+x;
                        int jj = j+y;
                        if(ii>=0 && jj>=0 && ii<n && jj<m && grid[ii][jj]){
                            ds.ubs(ii*m+jj,i*m+j);
                            mx = max(mx,ds.getsize(ds.findpar(i*m+j)));
                        }
                    }   
                }
            }
            i++;
        }
        dir = {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]) continue;
                set<int> parents;
                for(auto &[x,y]: dir){
                    int ii = i+x;
                    int jj = j+y;
                    if(ii>=0 && jj>=0 && ii<n && jj<m && grid[ii][jj]){
                        parents.insert(ds.findpar(ii*m+jj));
                    }
                }
                int size = 1;
                for(auto it: parents){
                    size += ds.getsize(it);
                }
                mx = max(mx,size);
            }
        }
        return mx;
    }
};