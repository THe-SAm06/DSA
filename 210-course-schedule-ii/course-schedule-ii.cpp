class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> ans;
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        
        for(auto u : edges){
            adj[u[1]].push_back(u[0]);
            indegree[u[0]]++;
        }
        
        queue<int> q;
        
        for(int i =0;i<V;i++) if(indegree[i]==0) q.push(i);
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int v:adj[node]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        if(ans.size()==V) return ans;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return topoSort(numCourses,prerequisites);
    }
};