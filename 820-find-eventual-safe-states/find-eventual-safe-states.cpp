class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<bool>& vis,stack<int>& st){
        vis[node] = true;

        for(int v : graph[node]){
            if(!vis[v]) dfs(v,graph,vis,st);
        }

        st.push(node);
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> topsort;
        vector<bool> vis(graph.size(),false);
        stack<int> st;
        for(int i=0;i<graph.size();i++){
            if(!vis[i]) dfs(i,graph,vis,st);
        }
        while(!st.empty()){
            topsort.push_back(st.top());
            st.pop();
        }
        for(int a:topsort) cout<<a<<" ";
        unordered_set<int> safe_node;
        for(int i = topsort.size()-1;i>=0;i--){
            if(graph[topsort[i]].empty()){
                safe_node.insert(topsort[i]);
                continue;
            }
            bool flag = true;
            for(int u:graph[topsort[i]]){
                if(safe_node.find(u)==safe_node.end()){
                    flag = false;
                    break;
                }
            }
            if(flag) safe_node.insert(topsort[i]);
        }
        vector<int> ans(safe_node.begin(),safe_node.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};