class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size(), n = matrix[0].size();
        int i=0, j=0;

        while(ans.size()<m*n){

            while(j<n && matrix[i][j]!=101){
                ans.push_back(matrix[i][j]);
                matrix[i][j]=101;
                j++;
            }

            j--;
            i++;

            while(i<m && matrix[i][j]!=101){
                ans.push_back(matrix[i][j]);
                matrix[i][j]=101;
                i++;
            }

            i--;
            j--;

            while(j>=0 && matrix[i][j]!=101){
                ans.push_back(matrix[i][j]);
                matrix[i][j]=101;
                j--;
            }

            j++;
            i--;

            while(i>=0 && matrix[i][j]!=101){
                ans.push_back(matrix[i][j]);
                matrix[i][j]=101;
                i--;
            }

            i++;
            j++;
        }

        return ans;
    }
};