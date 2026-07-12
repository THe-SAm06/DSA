class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis,int& count,int& nc2){
        count++;
        nc2 += adj[node].size();
        vis[node] = true;
        for(int v: adj[node]){
            if(!vis[v]) dfs(v,adj,vis,count,nc2);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        vector<bool> vis(n);
        int count, nc2;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                count = 0;
                nc2 = 0;
                dfs(i,adj,vis,count,nc2);
                if(count == 1) ans++;
                else if(count*(count-1) == nc2) ans++;
            }
        }
        return ans;
    }
};