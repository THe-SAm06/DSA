class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeros = 0;
        int mx = 0;
        while(r<nums.size()){
            if(!nums[r]) zeros++;
            while(zeros>k){
                if(!nums[l]) zeros--;
                l++;
            }
            mx = max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};