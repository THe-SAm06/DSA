class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int a:nums){
            hash[a]++;
            if(hash[a]>(nums.size()/2)) return a;
        }
        return 0;
    }
};