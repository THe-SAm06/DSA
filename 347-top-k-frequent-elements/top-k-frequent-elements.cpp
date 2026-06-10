class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int a:nums) mp[a]++;
        for(auto [num,freq]:mp){
            pq.push({freq,num});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        return ans;
    }
};