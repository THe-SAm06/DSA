class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<vector<int>> pq;
        for(int i=0;i<mat.size();i++){
            int c = lower_bound(mat[i].begin(),mat[i].end(),0,greater<int>()) - mat[i].begin();
            pq.push({c,i});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans(k);
        while(!pq.empty()){
            ans[k-1] = pq.top()[1];
            pq.pop();
            k--;
        }
        return ans;
    }
};