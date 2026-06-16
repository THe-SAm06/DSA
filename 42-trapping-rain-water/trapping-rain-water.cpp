class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n);
        vector<int> left(n);
        right[n-1] = -1;
        left[0] = -1;
        int rmx = height[n-1];
        int lmx = height[0];
        for(int i =1;i<n-1;i++){
            if(height[i]>=lmx){
                left[i] = -1;
                lmx = height[i];
            }
            else left[i] = lmx;
            if(height[n-i-1]>=rmx){
                right[n-i-1] = -1;
                rmx = height[n-i-1];
            }
            else right[n-i-1] = rmx;
        }
        left[n-1] = lmx;
        right[0] = rmx;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(left[i]!=-1 && right[i]!=-1){
                ans+= min(left[i],right[i])-height[i];
            }
        }
        return ans;
    }
};