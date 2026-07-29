class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros;

        int count;

        for(int i = 0;i<n;i++){
            count = 0;
            for(int j = n-1;j>=0;j--){
                if(grid[i][j]) break;
                count++;
            }
            zeros.push_back(count);
        }
        int swaps = 0;
        int j;
        for(int i = 0;i<n;i++){
            if(zeros[i] >= n-i-1) continue;
            j = i+1;
            while(j<n){
                if(zeros[j]>=n-i-1){
                    while(j>i){
                        swap(zeros[j-1],zeros[j]);
                        swaps++;
                        j--;
                    }
                    break;
                }
                j++;
            }
            if(j==n) return -1;
        }
        return swaps;
    }
};