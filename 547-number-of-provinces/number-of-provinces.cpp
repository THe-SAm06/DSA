class Solution {
public:
    void dfs(int node,vector<bool>& visited,vector<vector<int>>& graph){
        if(visited[node]) return;
        visited[node] = true;
        for(int i = 0;i<graph[node].size();i++){
            if(graph[node][i]) dfs(i,visited,graph);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int ans = 0;
        for(int i =0;i<isConnected.size();i++){
            if(!visited[i]){
                ans++;
                dfs(i,visited,isConnected);
            }
        }
        return ans;
    }
};