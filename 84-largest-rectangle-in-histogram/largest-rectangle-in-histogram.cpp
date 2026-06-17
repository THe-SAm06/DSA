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
};