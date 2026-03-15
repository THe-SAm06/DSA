class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum = 0 , len=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                sum = sum - 1;
            }
            else sum++;
            if(mp.find(sum)!=mp.end()){
                len = max(len,i-mp[sum]);
            }
            else mp[sum]=i;
        }
        return len;
    }
};