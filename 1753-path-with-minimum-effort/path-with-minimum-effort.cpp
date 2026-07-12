class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        if(m==1 && n==1) return 0;

        vector<vector<int>> df(m,vector<int>(n,INT_MAX));
        df[0][0] = 0;

        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});

        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!pq.empty()){
            auto [diff,idx] = pq.top();
            auto [i,j] = idx;
            pq.pop();

            if(i==m-1 && j==n-1) break;

            if(diff>df[i][j]) continue;

            for(auto p:dir){
                int ii = i+p.first;
                int jj = j+p.second;
                if(ii>=0 && jj>=0 && ii<m && jj<n){
                    int neweffort = max(diff,abs(heights[i][j]-heights[ii][jj]));
                    if(neweffort<df[ii][jj]){
                        df[ii][jj] = neweffort;
                        pq.push({neweffort,{ii,jj}});
                    }
                }
            }
        }
        return df[m-1][n-1];
    }
};