class Solution {
public:
    int ones(vector<int> num){
        int ct=0;
        for(int n : num){
            if(n==1) ct++;
        }
        return ct;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int mx = 0;
        int ans = 0;
        for(int i =0;i<mat.size();i++){
            if(ones(mat[i])>mx){
                mx = ones(mat[i]);
                ans = i;
            }
        }
        return {ans,mx};
    }
};