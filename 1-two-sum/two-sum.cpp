class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                a={mp[target-nums[i]],i};
                return a;
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};