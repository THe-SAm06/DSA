class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        int i = 2;
        while(1){
            if(1<<i > n) return 1<<i;
            i++;
        }
    }
};