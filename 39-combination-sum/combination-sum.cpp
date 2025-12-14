class Solution {
public:
    void rec(int i,vector<vector<int>> &sub,int sum,vector<int> &v,int target,vector<int> &candidates){
        if(sum>target){
            return;
        }
        if(i==candidates.size()){
            if(sum==target){
                sub.push_back(v);
            }
            return;
        }
       
        v.push_back(candidates[i]);
        rec(i,sub,sum+candidates[i],v,target,candidates);
        v.pop_back();
        rec(i+1,sub,sum,v,target,candidates);
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sub;
        vector<int> v;
        rec(0,sub,0,v,target,candidates);
        return sub;
    }
};