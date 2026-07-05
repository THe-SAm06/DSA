class Solution {
public:
    bool dfs(int node,int color,vector<vector<int>>& graph,vector<pair<bool,int>>& vis){
        vis[node].first = true;
        vis[node].second = color;
        for(int v:graph[node]){
            if(vis[v].first && vis[v].second==color) return false;
            if(!vis[v].first){
                if(!dfs(v,!color,graph,vis)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<pair<bool,int>> vis(graph.size());
        for(auto u:graph){
            for(int v:u){
                if(!vis[v].first){
                    if(!dfs(v,0,graph,vis)) return false;
                }
            }
        }
        return true;
    }
};