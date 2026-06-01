class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int l = intervals[0][0];
        int r = intervals[0][1];
        vector<vector<int>> ans;
        for(int i = 1;i<intervals.size();i++){
            if((intervals[i][0]<=l && intervals[i][1]<=r && intervals[i][1]>=l) || (intervals[i][1]>=r && intervals[i][0]>=l && intervals[i][0]<=r) || (intervals[i][0]<=l && intervals[i][1]>=r) || (intervals[i][0]>=l && intervals[i][1]<=r) ){
                l = min(min(l,r),min(intervals[i][0],intervals[i][1]));
                r = max(max(l,r),max(intervals[i][0],intervals[i][1]));
            }
            else{
                ans.push_back({l,r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        ans.push_back({l,r});
        return ans;
    }
};