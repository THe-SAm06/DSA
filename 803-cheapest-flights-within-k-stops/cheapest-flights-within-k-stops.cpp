#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& vec : flights) {
            adj[vec[0]].push_back({vec[1], vec[2]});
        }

        // Standard Queue tracking only: {node, current_accumulated_price}
        queue<pair<int, int>> q;
        q.push({src, 0});

        vector<int> price(n, INT_MAX);
        price[src] = 0;

        int stops = 0;

        // Level-order layer traversal loop
        while (!q.empty() && stops <= k) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                auto [node, p] = q.front();
                q.pop();

                for (auto& [v, pr] : adj[node]) {
                    // Level-order guarantees stops are uniform; 
                    // we safely update if we find a cheaper option for this layer stage
                    if (p + pr < price[v]) {
                        price[v] = p + pr;
                        q.push({v, price[v]});
                    }
                }
            }
            stops++; // Increment the stop counter after finishing the whole layer floor
        }

        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};