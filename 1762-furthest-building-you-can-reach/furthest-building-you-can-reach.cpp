class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int diff;
        for(int i =0;i<heights.size()-1;i++){
            diff = heights[i+1]-heights[i];
            if(diff<=0) continue;
            pq.push(diff);
            if(pq.size()>ladders){
                bricks -= pq.top();
                if(bricks<0) return i;
                pq.pop();
            }
        }
        return heights.size()-1;
    }
};