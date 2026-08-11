class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int not_take = 0;
        int take = nums[0];

        int p1;

        for(int i = 1;i<n-1;i++){
            p1 = not_take;
            not_take = max(not_take,take);
            take = nums[i] + p1;
        }

        int m1 =max(take,not_take);

        not_take = 0;
        take = nums[1];

        for(int i = 2;i<n;i++){
            p1 = not_take;
            not_take = max(not_take,take);
            take = nums[i] + p1;
        }

        int m2 = max(not_take,take);

        return max(m1,m2);
    }
};