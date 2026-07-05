class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int mx = 0;
        for(int a:nums){
            string s = to_string(a);
            sort(s.begin(),s.end());
            int r = s[s.size()-1]-'0';
            int l = s[0] - '0';
            mx = max(mx,r-l);
        }
        int ans = 0;
        for(int a:nums){
            string s = to_string(a);
            sort(s.begin(),s.end());
            int r = s[s.size()-1]-'0';
            int l = s[0] - '0';
            if((r-l) == mx) ans += a;
        }
        return ans;
    }
};