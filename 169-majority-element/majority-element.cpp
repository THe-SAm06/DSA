class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int ele;
        for(int a : nums){
            if(count==0){
                ele = a;
                count = 1;
            }
            else if(a == ele) count++;
            else count--;
        }
        return ele;
    }
};