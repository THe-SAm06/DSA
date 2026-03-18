class Solution {
public:
    int bs(vector<int>& nums,int l,int h){
        if(l==h){
            return nums[l];
        }
        int mid = l+(h-l)/2;
        if((h-l+1)%4 == 1){
            if(nums[mid]==nums[mid+1]){
                return bs(nums,mid+2,h);
            }
            else if(nums[mid]==nums[mid-1]) return bs(nums,l,mid-2);
            else return nums[mid];
        }
        else{
            if(nums[mid]==nums[mid+1]){
                return bs(nums,l,mid-1);
            }
            else if(nums[mid]==nums[mid-1]) return bs(nums,mid+1,h);
            else return nums[mid];
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        return bs(nums,0,nums.size()-1);
    }
};