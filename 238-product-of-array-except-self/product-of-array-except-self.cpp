class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> a;
        int prefix = 1;
        a.push_back(1);
        for (int i=0;i<nums.size()-1;i++){
            prefix = prefix * nums[i];
            a.push_back(prefix);
        }
        int suffix=1;
        for(int i=nums.size()-1;i>0;i--){
            suffix = suffix * nums[i];
            a[i-1] = a[i-1] * suffix;
        }
        return a;
    }
};