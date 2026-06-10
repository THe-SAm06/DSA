class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int a:nums) pq.push(a);
        int ans =0;
        long long a,b;
        while(!pq.empty()){
            if(pq.top()>=k) break;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(a*2+b);
            ans++;
        }
        return ans;
    }
};