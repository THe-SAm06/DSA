class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size();
        int lr = 0, rr = matrix[0].size();
        while(l<=r){
            int mid=(l+r)>>1;
            if(mid<matrix.size() && target>= matrix[mid][0] && target<=matrix[mid][matrix[0].size()-1]){
                while(lr<=rr){
                    int midr = (lr+rr)>>1;
                    if(matrix[mid][midr]==target) return true;
                    else if(matrix[mid][midr]>target) rr = midr-1;
                    else lr = midr+1;
                }
                return false;
            }
            else if(mid<matrix.size() && target < matrix[mid][0]) r=mid-1;
            else l = mid+1;
        }
        return false;
    }
};