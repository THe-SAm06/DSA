class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> past;
        for(int i = 0;i<numRows;i++){
            vector<int> curr(i+1);
            int ans = 1;
            for(int j=0;j<=i/2;j++){
                curr[j] = ans;
                curr[i-j] = curr[j];
                ans = ans*(i-j)/(j+1);
            }
            past.push_back(curr);
        }
        return past;
    }
};