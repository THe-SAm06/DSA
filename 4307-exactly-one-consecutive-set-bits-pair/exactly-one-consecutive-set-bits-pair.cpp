class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count = 0;
        int last=-1;
        int curr = n%2;
        n = n/2;
        while (n > 0) {
            if(last==1 && curr==1) count++;
            last = curr;
            curr = n%2;
            n = n/2;
        }
        if(last==curr) count++;

        return count == 1;
    }
};