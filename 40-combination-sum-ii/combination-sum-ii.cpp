class Solution {
public:
    void backtracking(int start,int sum,int target,vector<vector<int>> &sol,vector<int> &v,vector<int> &c){
        if(sum>target){
            return;
        }
            if(sum==target){
                sol.push_back(v);
                return;
            }
            
        for(int i=start;i<c.size();i++){
            if(i>start && c[i]==c[i-1]){
                continue;
            }
            if(c[i]>target) break;
            v.push_back(c[i]);
            backtracking(i+1,sum+c[i],target,sol,v,c);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> sol;
        vector<int> v;
        backtracking(0,0,target,sol,v,candidates);
        return sol;
    }
};