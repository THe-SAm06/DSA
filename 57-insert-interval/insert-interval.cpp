class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};

        int l = newInterval[0];
        int r = newInterval[1];

        int i = 0;
        int n = intervals.size();

        vector<vector<int>> ans;

        while (i < n) {
            // Current interval is completely before newInterval
            if (intervals[i][1] < l) {
                ans.push_back(intervals[i]);
                i++;
            }
            // Current interval is completely after newInterval
            else if (intervals[i][0] > r) {
                ans.push_back({l, r});

                while (i < n) {
                    ans.push_back(intervals[i]);
                    i++;
                }

                return ans;
            }
            // Overlapping interval
            else {
                l = min(l, intervals[i][0]);
                r = max(r, intervals[i][1]);
                i++;
            }
        }

        // newInterval comes after all intervals
        ans.push_back({l, r});

        return ans;
    }
};