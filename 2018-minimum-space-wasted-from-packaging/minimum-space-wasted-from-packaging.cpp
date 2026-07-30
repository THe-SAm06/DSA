class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size();
        int m = boxes.size();

        sort(packages.begin(),packages.end());
        vector<bool> pos(m);

        long long p_sum = accumulate(packages.begin(),packages.end(),0LL);

        bool ispos = false;
        for(int i = 0;i<m;i++){
            sort(boxes[i].begin(),boxes[i].end());
            if(boxes[i].back()>=packages.back()){
                pos[i] = true;
                ispos = true;
            }
        }

        if(!ispos) return -1;
        long long b_sum;
        long long min_bsum = LLONG_MAX;
        int k;

        for(int i = 0;i<m;i++){
            if(!pos[i]) continue;
            b_sum = 0;
            k = 0;
            for(int& b: boxes[i]){
                int j = upper_bound(packages.begin()+k,packages.end(),b) - packages.begin();
                b_sum += 1LL*b*(j-k);
                if(j == n) break;
                k = j;
            }
            min_bsum = min(min_bsum,b_sum);
        }
        const int MOD = 1e9 + 7;
        return (min_bsum - p_sum) % MOD;
    }
};