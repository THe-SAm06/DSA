class Solution {
public:
    long long power(long long a, long long b, int mod) {
        long long ans = 1;

        while(b > 0) {
            if(b & 1)
                ans = (ans * a) % mod;

            a = (a * a) % mod;
            b /= 2;
        }

        return ans;
    }

    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;

        int shifts = 32 - __builtin_clz(n);
        long long t_shifts = 0;
        long long ans = 0;

        while(n > 0) {
            long long p = power(2, t_shifts, mod);

            ans = (ans + (n * p) % mod) % mod;

            t_shifts += shifts;

            if((n & (n - 1)) == 0)
                shifts--;

            n--;
        }

        return ans;
    }
};