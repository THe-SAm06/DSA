class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int mx = nums[0];
        int i = 0;
        for(int a: nums){
            mx = max(mx,a);
            prefix[i] = gcd(mx,nums[i]);
            i++;
        }
        sort(prefix.begin(),prefix.end());
        long long sum = 0;
        for(int i = 0;i<n/2;i++){
            sum += gcd(prefix[i],prefix[n-i-1]);
        }

        return sum;
    }
};