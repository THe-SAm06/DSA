class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minprod = nums[0],maxprod = nums[0], res=nums[0];
        for(int i = 1; i<nums.size();i++){
            int v1 = nums[i];
            int v2 = nums[i]*minprod;
            int v3 = nums[i]*maxprod;
            minprod = min(v1,min(v3,v2));
            maxprod = max(v1,max(v3,v2));
            res = max(res,maxprod);
        }
        return res;
    }
};