class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> pse(n), nse(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                nse[st.top()] = i;
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> pre(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
            pre[0][j] = matrix[0][j] - '0';

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    pre[i][j] = pre[i - 1][j] + 1;
                else
                    pre[i][j] = 0;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, largestRectangleArea(pre[i]));
        }

        return ans;
    }
};