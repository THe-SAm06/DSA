class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> starting_at(n);
        for(int i=0;i<queries.size();i++){
            starting_at[queries[i][0]].push_back(queries[i][1]);
        }
        priority_queue<int> pq;
        vector<int> diff(n+1,0);
        int active_queries = 0;
        int used_queries = 0;
        for(int i =0;i<nums.size();i++){
            active_queries += diff[i];
            for(int r:starting_at[i]){
                pq.push(r);
            }
            while(active_queries<nums[i]){
                if(pq.empty() || pq.top()<i) return -1;
                int max_r = pq.top();
                pq.pop();
                active_queries++;
                used_queries++;
                diff[max_r+1]--;
            }
        }
        return queries.size()-used_queries;
    }
};