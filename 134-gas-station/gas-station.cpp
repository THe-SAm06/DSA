class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int del = 0;
        for(int i = 0;i<gas.size();i++){
            del += gas[i]-cost[i];
        }
        if(del<0) return -1;
        int ans = 0;
        int currcost = 0;
        for(int i =0;i<gas.size();i++){
            currcost += gas[i] - cost[i];
            if(currcost<0){
                ans = i+1;
                currcost =0;
            }
        }
        return ans;
    }
};