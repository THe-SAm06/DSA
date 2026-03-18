class Solution {
public:
    int bs(vector<int>& nums,int l,int h){
        if(l==h) return l;
        if(h==l+1){
            if(nums[l]>nums[h]) return l;
            else return h;
        }
        int mid = l+(h-l)/2;
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
            return mid;
        }
        if(nums[mid]<nums[mid+1]){
            return bs(nums,mid+1,h);
        }
        else return bs(nums,l,mid-1);
    }
    int findPeakElement(vector<int>& nums) {
        return bs(nums,0,nums.size()-1);
    }
};