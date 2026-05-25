class Solution {
public:
    int fun(vector<int>& nums, int k){
        int r=0, l=0, currk=0, count=0;
        if(k<0) return 0;
        while(r<nums.size()){
            if(nums[r]%2==1) currk++;
            while(currk>k){
                if(nums[l]%2==1) currk--;
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};