class Solution {
public:
    bool recur(vector<int>& nums, int target,int l,int h){
        if(l>h){
            return false;
        }
        int mid = (l+h)/2;
        if(nums[mid] == target) return true;
        if(nums[mid]==nums[l] && nums[l]==nums[h]){
            return recur(nums,target,l+1,h-1);
        }
        if(nums[mid]>=nums[l]){
            if(target<nums[mid] && target>=nums[l]){
                return recur(nums,target,l,mid-1);
            }
            else return recur(nums,target,mid+1,h);
        }
        else{
            if(target>nums[mid] && target<=nums[h]){
                return recur(nums,target,mid+1,h);
            }
            else return recur(nums,target,l,mid-1);
        }
    }
    bool search(vector<int>& nums, int target) {
        return recur(nums,target,0,nums.size()-1);
    }
};