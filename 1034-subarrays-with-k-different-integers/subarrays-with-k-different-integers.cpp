class Solution {
public:
    int fun(vector<int>& nums, int k){
        unordered_map<int,int> hash;
        int l=0, r=0, count=0;
        if(k<0) return 0;
        while(r<nums.size()){
            hash[nums[r]]++;
            while(hash.size()>k){
                hash[nums[l]]--;
                if(hash[nums[l]]==0) hash.erase(nums[l]);
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};