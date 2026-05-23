class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum;
        int currsum=0;
        for(int i=0;i<k;i++){
            currsum+=cardPoints[i];
        }
        sum = currsum;
        int r=cardPoints.size()-1;
        for(int i =k-1;i>=0;i--){
            currsum += cardPoints[r--] - cardPoints[i];
            sum = max(currsum,sum);
        }
        return sum;
    }
};