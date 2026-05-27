class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()>1){
            int j= n-2;
            while(j>=0 && nums[j]>=nums[j+1]) j--;
            if(j<0){
            reverse(nums.begin(),nums.end());
            }
            else{
                for(int i=n-1;i>=0;i--){
                    if(nums[i]>nums[j]){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
                reverse(nums.begin()+j+1,nums.end());
            }
        }
    }
};