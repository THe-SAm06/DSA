class Solution {
    int rec(int idx,int canbuy,vector<int>& p,int dp[p.size()][2][3],int count){
        if(idx>=p.size()) return 0;
        if(count>=2 && canbuy) return 0;
        
        if(dp[idx][canbuy][count]!=-1) return dp[idx][canbuy][count];

        int ans = INT_MIN;

        int buy, not_buy;

        if(canbuy){
            buy = -p[idx] + rec(idx+1,0,p,dp,count+1);
            not_buy = rec(idx+1,1,p,dp,count);
            ans = max(not_buy,buy);
        }
        else{
            ans = max(p[idx] + rec(idx+1,1,p,dp,count),rec(idx+1,0,p,dp,count));
        }
        return dp[idx][canbuy][count] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()][2][3];
        memset(dp,-1,sizeof(dp));
        return rec(0,1,prices,dp,0);
    }
};