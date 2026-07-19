class Solution {
public:
    vector<pair<int,int>> dir = {
        {2,1},{-2,-1},{2,-1},{-2,1},
        {1,2},{-1,-2},{1,-2},{-1,2}
    };

    bool vis[8][8][2];

    bool dfs(vector<int> curr, vector<int>& target, int moves) {

        if (curr[0] == target[0] && curr[1] == target[1] && moves % 2 == 0)
            return true;

        vis[curr[0]][curr[1]][moves % 2] = true;

        for (auto [x, y] : dir) {
            int i = curr[0] + x;
            int j = curr[1] + y;

            if (i >= 0 && j >= 0 && i < 8 && j < 8 &&
                !vis[i][j][(moves + 1) % 2]) {

                if (dfs({i, j}, target, moves + 1))
                    return true;
            }
        }

        return false;
    }

    bool canReach(vector<int>& start, vector<int>& target) {
        memset(vis, false, sizeof(vis));
        return dfs(start, target, 0);
    }
};
