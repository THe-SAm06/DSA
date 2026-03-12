class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0,maxsum=INT_MIN;
        for(int a:nums){
            cursum = cursum+a;
            maxsum = max(maxsum,cursum);
            if(cursum < 0 ){
                cursum =0;
            }
        }
        return maxsum;
    }
};