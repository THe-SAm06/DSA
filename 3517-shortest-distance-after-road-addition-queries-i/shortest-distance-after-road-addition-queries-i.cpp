class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector<int> adj[n];
        for(int i = 0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        vector<int> ans;

        for(auto vec: queries){

            adj[vec[0]].push_back(vec[1]);
            queue<int> q;
vector<bool> vis(n, false);

q.push(0);
vis[0] = true;

int level = 0;
bool found = false;

            while (!q.empty() && !found) {
                int sz = q.size();

                while (sz--) {
                    int node = q.front();
                    q.pop();

                    if (node == n - 1) {
                        ans.push_back(level);
                        found = true;
                        break;
                    }

                    for (int v : adj[node]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }

                level++;
            }
                    }
        return ans;
    }
};