class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> st(nums.begin(),nums.end());
        int p = *st.begin() -1;

        int curr = 0;
        int ans = 1;
        for(int a: st){
            if(a == p+1) curr++;
            else{
                ans = max(curr,ans);
                curr = 1;
            }
            p = a;
        }
        ans = max(ans,curr);
        return ans;
    }
};