class Solution {
public:
    bool fun(vector<int>& c,int mid){
        int count = 0;
        for(int a : c){
            if(a>=mid) count++;
        }
        return count>=mid;
    }
    int hIndex(vector<int>& citations) {
        int l = 0 ;
        int n = citations.size();
        int r = min(*max_element(citations.begin(),citations.end()),n);
        int ans;
        while(l<=r){
            int mid = (l+r)/2;
            if(fun(citations,mid)){
                ans = mid;
                l=mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};