class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int i=0, j=1;
        for(int a:nums){
            if(a>0){
                ans[i]=a;
                if(i+2<nums.size()) i=i+2;
            }
            else{
                ans[j]=a;
                if(j+2<nums.size()) j=j+2;
            }
        }
        return ans;
    }
};