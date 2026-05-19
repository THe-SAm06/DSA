class Solution {
public:
    bool fun(vector<int>& nums,int n,int t){
        int sum = 0;
        for(int i =0 ;i<nums.size();i++){
            if(nums[i]%n==0) sum+=nums[i]/n;
            else sum+=nums[i]/n+1;
        }
        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx = nums[0];
        for(int a:nums){
            mx = max(mx,a);
        }
        int mn = 1;
        while(mn<mx){
            int mid = mn+(mx-mn)/2;
            if(fun(nums,mid,threshold)) mx=mid;
            else mn = mid+1;
        }
        return mn;
    }
};