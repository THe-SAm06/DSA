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
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        DisjointSet ds(accounts.size());
        int j = 0;
        for(auto vec : accounts){
            for(int i  = 1;i<vec.size();i++){
                if(mp.find(vec[i])!=mp.end()){
                    ds.ubr(j,mp[vec[i]]);
                }
                else mp[vec[i]] = j;
            }
            j++;
        }
        vector<vector<string>> merged(accounts.size());
        vector<vector<string>> ans;

        for(auto [str,idx]: mp){
            int par = ds.findpar(idx);
            merged[par].push_back(str);
        }

        for(int i = 0;i<merged.size();i++){

            if(merged[i].empty()) continue;
            vector<string> temp;

            sort(merged[i].begin(),merged[i].end());

            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(),merged[i].begin(),merged[i].end());

            ans.push_back(temp);
        }

        return ans;
    }
};