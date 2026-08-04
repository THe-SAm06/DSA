class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        vector<int> pre(n);
        pre[0] = nums[0];

        for(int i =1;i<n;i++) pre[i] = pre[i-1] + nums[i];
        for(int i = 0;i<n;i++){
            if( pre[i]<0) pre[i] = ((pre[i] % k) + k) % k;
            else pre[i] = pre[i]%k;
        }

        unordered_map<int,int> mp;
        int mod;

        for(int i = 0;i<n;i++){
            if(pre[i] == 0) count++;
            if(mp.find(pre[i]) != mp.end()) count+= mp[pre[i]];
            mp[pre[i]]++;
        }
        return count;
    }
};