class Solution {
public:
    const int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                pq.push(sum);
            }
        }
        int sum = 0;
        for(int i = 1;i<=right;i++){
            if(i == left){
                while(i<=right){
                    sum = (sum+pq.top()) % MOD;
                    pq.pop();
                    i++;
                }
            }
            pq.pop();
        }
        return sum;
    }
};