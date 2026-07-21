class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        long long cost = 0;
        int kth = k;
        for(int a: nums){
            if(a < k) k = k-a;
            else{
                cost += (a-k+kth-1LL)/kth;
                k += 1LL*((a-k+kth-1LL)/kth) * kth;
                k = k -a;
            } 
        }
        cost %= MOD;
        return cost*(cost+1)/2 % MOD;
    }
};