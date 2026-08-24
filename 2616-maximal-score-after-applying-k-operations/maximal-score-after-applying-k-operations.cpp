class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;

        for(int a: nums) pq.push(a);

        int el;

        while(k--){
            el = pq.top();
            pq.pop();

            ans += el;

            if(el % 3 == 0) pq.push(el/3);
            else pq.push(el/3 + 1); 
        }

        return ans;
    }
};