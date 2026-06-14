class Solution {
public:
    const int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0;i<n;i++){
            pq.emplace(nums[i],i);
        }
        int ans = 0;
        for(int i=1;i<=right;i++){
            auto [sum,idx] = pq.top();
            pq.pop();
            if(i>=left){
                ans = (ans+sum) %MOD;
            }
            if(idx+1<n){
                pq.push({sum+nums[idx+1],idx+1});
            }
        }
        return ans;
    }
};