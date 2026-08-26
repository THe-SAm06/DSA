class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for(int i = 1;i<nums.size();i++){
            ans[i] = ans[i-1] * nums[i-1];
            cout<<ans[i]<<" ";
        }
        int mul = nums.back();
        for(int i = nums.size()-2;i>=0;i--){
            ans[i] *= mul;
            mul *= nums[i];
        }

        return ans;
    }
};