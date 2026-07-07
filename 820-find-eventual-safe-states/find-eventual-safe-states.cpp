class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,vector<bool>& vis,vector<bool>& pathvis){
        
        if(vis[node]) return true;
        
        vis[node] = true;
        pathvis[node] = true;
        
        for(int v:adj[node]){
            if(!vis[v]){
                if(dfs(v,adj,vis,pathvis)) return true;
            }
            if(pathvis[v]) return true;
        }
        
        pathvis[node] = false;
        
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size());
        vector<bool> pathvis(graph.size());
        
        for(int i = 0;i<graph.size();i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis);
            }
        }
        vector<int> ans;
        for(int i =0;i<vis.size();i++){
            if(!pathvis[i]) ans.push_back(i);
        }
        return ans;
    }
};