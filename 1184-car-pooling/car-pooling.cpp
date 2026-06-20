class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int mx = INT_MIN;
        for(int i = 0;i<trips.size();i++){
            mx = max(mx,trips[i][2]);
        }
        vector<int> diff(mx,0);
        for(int i =0;i<trips.size();i++){
            int L = trips[i][1];
            int R = trips[i][2];

            diff[L] += trips[i][0];
            if(diff[L]>capacity) return false;
            if(R<mx){
                if(diff[R]>capacity) return false;
                diff[R] -= trips[i][0];
            }
        }
        if(diff[0]> capacity) return false;
        for(int i = 1;i<mx;i++){
            diff[i] += diff[i-1];
            if(diff[i]>capacity) return false;
        }
        return true;
    }
};