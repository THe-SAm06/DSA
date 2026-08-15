class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int found = false;
        for(int a: nums){
            if(a) found = true;
            ans ^= a;
        }
        if(!found) return 0;
        if(ans != 0) return n;
        return n-1;
    }
};