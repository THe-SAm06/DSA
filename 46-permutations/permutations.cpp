class Solution {
public:
   void backtrack(int ind,vector<int> &nums,vector<vector<int>> &p){
    if(ind==nums.size()){
        p.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++){
        swap(nums[i],nums[ind]);
        backtrack(ind+1,nums,p);
        swap(nums[i],nums[ind]);
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> p;
        backtrack(0,nums,p);
        return p;
    }
};