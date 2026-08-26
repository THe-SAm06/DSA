class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int width;
        int ans = 0;

        while(r < height.size()){
            width = min(height[l] , height[r]);
            ans = max(ans, (r-l) * width);

            height[l]<height[r] ? l++ : r--;
        }

        return ans;
    }
};