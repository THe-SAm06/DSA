class Solution {
public:
    void dfs(int node,vector<bool> &sus,vector<vector<int>> &adj){
        sus[node] = true;

        for(int v: adj[node]){
            if(!sus[v]) dfs(v,sus,adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> sus(n);
        vector<vector<int>> adj(n);
        for(int i = 0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        dfs(k,sus,adj);
        for(int i = 0;i<n;i++){
            if(!sus[i]){
                for(int v:adj[i]){
                    if(sus[v]){
                        vector<int> ans;
                        for(int i = 0;i<n;i++) ans.push_back(i);
                        return ans;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(!sus[i]) ans.push_back(i);
        }

        return ans;
    }
};