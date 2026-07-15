class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node])
                continue;

            if(node == n-1) break;

            for (auto &[adjNode, wt] : adj[node]) {

                long long newDist = dis + wt;

                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];
                    pq.push({newDist, adjNode});
                }
                else if (newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};