class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans = grid;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int n_idx = (((i*n)+j) + k) % (m*n);
                int n_i = n_idx/n;
                int n_j = n_idx % n;
                ans[n_i][n_j] = grid[i][j];
            }
        }
        return ans;
    }
};