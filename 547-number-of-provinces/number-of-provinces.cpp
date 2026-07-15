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
        int no_ofprov() const{
            int count = 0;
            for(int i = 0;i<par.size();i++){
                if(par[i] == i) count++;
            }
            return count;
        }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]) ds.ubr(i,j);
            }
        }
        return ds.no_ofprov();
    }
};