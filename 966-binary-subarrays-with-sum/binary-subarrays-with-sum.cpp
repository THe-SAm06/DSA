class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> pre(nums.size());
        pre[0] = nums[0];
        for(int i =1;i<nums.size();i++){
            pre[i] = pre[i-1] + nums[i];
        }
        unordered_map<int,int> mp;
        int count = 0;
        for(int i =0;i<nums.size();i++){
            if(pre[i] == goal) count++;
            if(mp.find(pre[i]-goal)!=mp.end()) count += mp[pre[i]-goal];
            mp[pre[i]]++;
        }
        return count;
    }
};