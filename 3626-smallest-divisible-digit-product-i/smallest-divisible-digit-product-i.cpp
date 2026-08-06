class Solution {
public:
    int fun(int n){
        int sum = 1;
        while(n){
            sum *= n % 10;
            n = n/10;
        }
        return sum;
    }
    int smallestNumber(int n, int t) {
        while(1){
            if(fun(n)%t == 0) return n;
            n += 1;
        }
        return 0;
    }
};