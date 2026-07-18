class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int a : nums){
            mx = max(mx,a);
            mn = min(mn,a);
        }
        return gcd(mx,mn);
    }
};