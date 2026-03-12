class Solution {
public:
    int bs(vector<int>& nums,int l,int h){
        if(l>=h) return nums[l];
        int mid = (l+h)/2;
        if(mid<h && nums[mid]>nums[mid+1]) return nums[mid+1];
        if(mid>0 && nums[mid]<nums[mid-1]) return nums[mid];
        if(nums[mid]<nums[h]){
            return bs(nums,l,mid-1);
        }
        return bs(nums,mid+1,h);
    }
    int findMin(vector<int>& nums) {
        return bs(nums,0,nums.size()-1);
    }
};