class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<tuple<double,int,int>> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({(double)arr[i]/arr[j],i,j});
                if(pq.size()>k) pq.pop();
            }
        }
        auto [a,b,c] = pq.top();
        return {arr[b],arr[c]};
    }
};