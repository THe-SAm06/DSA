class DisjointSet{
private:
    vector<int> rank;
    vector<int> par;
public:
    DisjointSet(int n) :rank(n+1,0), par(n+1){
        for(int i = 0;i<=n;i++) par[i] = i;
    }
    int findpar(int u){
        if(par[u] == u) return u;
        return par[u] = findpar(par[u]);
    }
    void ubr(int u,int v){
        int pu = findpar(u);
        int pv = findpar(v);

        if(rank[pu] >= rank[pv]){
            par[pv] = pu;
            rank[pu]++;
        }
        else{
            par[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        if(n==1){
            for(auto q: queries){
                ans.push_back(true);
            }
            return ans;
        }
        DisjointSet ds(n);
        if(n==2){
            if(nums[1]-nums[0]<=maxDiff) ds.ubr(0,1);
        }
        int i = 0;
        int j = i+1;
        while(j<n){
            while(j<n && nums[j]-nums[i]<= maxDiff) j++;
            while(i<j-1){
                ds.ubr(i,j-1);
                i++;
            }
            if(j<n && nums[j]-nums[i]<=maxDiff) ds.ubr(i,j);
            i++, j++;
        }

        for(auto vec: queries){
            if(ds.findpar(vec[0]) == ds.findpar(vec[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};