class Solution {
public:
    void recur(vector<int>& candidates, int& target,vector<vector<int>>& arr,vector<int>& a,int& sum,int i){
        if(sum>target) return;
        if(sum==target){
            arr.push_back(a);
            return;
        }
        for(int j = i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
                a.push_back(candidates[j]);
                sum += candidates[j];
                recur(candidates,target,arr,a,sum,j+1);
                a.pop_back();
                sum -= candidates[j];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> arr;
        int sum = 0;
        vector<int> a;
        sort(candidates.begin(),candidates.end());
        recur(candidates,target,arr,a,sum,0);
        return arr;
    }
};