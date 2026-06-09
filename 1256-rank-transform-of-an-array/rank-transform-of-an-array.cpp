class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i = 0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        int i =1;
        while(pq.size()>0){
            auto a = pq.top();
            while(!pq.empty() && pq.top()[0]==a[0]){
                arr[pq.top()[1]] = i;
                pq.pop();
            }
            i++;
        }
        return arr;
    }
};