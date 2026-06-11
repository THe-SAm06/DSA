class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<vector<int>> pq;
        for(int i=0;i<mat.size();i++){
            int c = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0) break;
                c++;
            }
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