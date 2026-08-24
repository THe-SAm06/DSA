class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;

        unordered_map<int,int> mp;
        long long ans = 0;

        long long sum = 0;

        while(r<nums.size()){
            sum += nums[r];
            mp[nums[r]]++;

            if(r-l+1>k){
                sum -= nums[l];
                mp[nums[l]]--;
                l++;
            }

            while(mp[nums[r]] > 1){
                sum -= nums[l];
                mp[nums[l]]--;
                l++;
            }
    
            if(r-l+1 == k){
                ans = max(sum,ans);
            }
            r++;
        }

        return ans;
    }
};