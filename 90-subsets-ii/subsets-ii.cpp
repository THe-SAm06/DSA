class Solution {
public:
    void recur(vector<int>& nums,vector<vector<int>>& arr,vector<int>& a,int i){
        arr.push_back(a);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            a.push_back(nums[j]);
            recur(nums,arr,a,j+1);
            a.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> arr;
        vector<int> a;
        sort(nums.begin(),nums.end());
        recur(nums,arr,a,0);
        return arr;
    }
};