class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre(n);
        pre[0] = stones[0];

        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1] + stones[i];
        }

        if(n==2) return pre[n-1]; 
        int score = pre[n-1];

        for(int i = n-2;i>=1;i--){
            score = max(score,pre[i] - score);
        }

        return score;
    }
};