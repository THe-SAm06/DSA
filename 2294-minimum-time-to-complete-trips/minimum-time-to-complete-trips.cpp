class Solution {
public:
    bool fun(long long mid,int k,vector<int>& time){
        long long currt = 0;
        for(int i = 0;i<time.size();i++){
            if(time[i]>mid) continue;
            currt += mid/time[i];
            if(currt >= k) return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int mn = *min_element(time.begin(),time.end());
        long long r = 1LL*mn*totalTrips;
        long long l = 1;

        long long mid;

        while(l<r){
            mid = (l+r)>>1;
            // cout<<l<<' '<<r<<'\n';
            if(fun(mid,totalTrips,time)) r= mid;
            else l = mid + 1;
        }

        return l;
    }
};