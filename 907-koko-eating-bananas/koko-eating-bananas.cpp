class Solution {
public:
    bool fun(vector<int> p,int h, int k){
        int count = 0;
        for(int a:p){
            if(a%k == 0) count += a/k;
            else count = count + 1 + a/k;
        }
        if(count<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        for(int i=0;i<piles.size();i++){
            if(fun(piles,h,piles[i])){
                    int l = 1;
                    int r = piles[i];
                    while(l<r){
                        int mid = l+(r-l)/2;
                        if(fun(piles,h,mid)) r=mid;
                        else l = mid+1;
                    }
                    return l;
                }
        }
        return 0;
    }
};