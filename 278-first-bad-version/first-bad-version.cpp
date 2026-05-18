// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0;
        int r = n;
        while(l<r){
            int mid = l+(r-l)/2;
            if(mid<r && !isBadVersion(mid)){
                l=mid+1;
            }
            if(isBadVersion(mid)){
                if(mid>l && !isBadVersion(mid-1)){
                    return mid;
                }
                else r=mid-1;
            }
        }
        return l;
    }
};