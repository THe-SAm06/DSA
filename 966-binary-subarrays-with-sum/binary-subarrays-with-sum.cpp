class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        vector<int> pre;
        pre.push_back(nums[0]);
        for(int i = 1; i<nums.size();i++){
            pre.push_back(pre[i-1]+nums[i]);
        }
        unordered_map<int,int> mp; 
        int sum = 0, count =0;
        for(int j =0 ; j<nums.size();j++){
            if(pre[j] == k) count++;
            if(mp.find(pre[j]-k)!=mp.end()) count+=mp[pre[j]-k];
            mp[pre[j]]++;
        }
        return count;
    }
};