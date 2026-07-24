class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> ans;
        unordered_set<int> pairs;

        for(int i = 0;i<n;i++){
            ans.insert(nums[i]);
            for(int j = i+1;j<n;j++){
                pairs.insert(nums[i]^nums[j]);
            }
        }
        for(int a: pairs){
            for(int j = 0;j<n;j++) ans.insert(nums[j]^a);
        }
        return ans.size();
    }
};