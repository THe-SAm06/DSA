class Solution {
public:
    int fun(vector<int>& nums, int goal){
        int l=0, r=0, sum=0, count=0;
        if(goal<0) return 0;
        while(r<nums.size()){
            sum+=nums[r];
            if(sum<=goal) count+=r-l+1;
            while(sum>goal){
                sum-=nums[l++];
                if(sum<=goal) count+=r-l+1;
            }
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums,goal)-fun(nums,goal-1);
    }
};