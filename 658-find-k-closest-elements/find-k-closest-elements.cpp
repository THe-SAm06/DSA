class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        vector<int> diff(arr.size());
        for(int i=0;i<arr.size();i++){
            diff[i] = abs(arr[i]-x);
            pq.push({diff[i],i});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};