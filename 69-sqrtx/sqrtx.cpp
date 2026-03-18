class Solution {
public:
    int bs(int x,int l ,int h){
        if(l==h) return l;
        int mid = l+(h-l)/2;
        if(mid<=x/mid && (mid+1)>x/(mid+1)) return mid;
        else if(mid > x/mid){
           return bs(x,l,mid-1);
        }
        return bs(x,mid+1,h);
    }
    int mySqrt(int x) {
        if(x==0) return 0;
        return bs(x,1,x/2);
    }
};