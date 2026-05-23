class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int ans=INT_MAX;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]>=nums[l]){
                ans = min(ans,nums[l]);
                l=mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                r=mid-1;
            }
        }
        return ans;
    }
};