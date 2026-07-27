class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long long ans = 0;
        int shifts = 0;
        for(int i = 1;i<=n;i++){
            if((i & (i-1)) == 0) shifts++;
            ans = (ans << shifts | i) % mod;
        }
        return ans;
    }
};