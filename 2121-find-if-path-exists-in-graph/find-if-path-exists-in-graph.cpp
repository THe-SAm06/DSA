class Solution {
public:
    bool dfs(int node,int dst,vector<vector<int>> &adj,vector<bool>& vis){
        if(node == dst) return true;
        vis[node] = true;

        for(int v: adj[node]){
            if(!vis[v]){
                if(dfs(v,dst,adj,vis)) return true;
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(auto vec: edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        vector<bool> vis(n);

        return dfs(source,destination,adj,vis);
    }
};