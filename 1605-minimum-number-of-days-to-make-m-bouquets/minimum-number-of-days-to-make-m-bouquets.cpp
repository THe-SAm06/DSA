class Solution {
    bool fun(vector<int>& arr,int m,int k,int mid){
        int blooms = 0;
        int count = 0;
        for(int a: arr){
            if(a <= mid) count++;
            else{
                blooms += count/k;
                count = 0;
            }
        }
        blooms += count/k;

        return blooms >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m > bloomDay.size() / k) return -1;
        int l = *min_element(bloomDay.begin(),bloomDay.end());
        int r = *max_element(bloomDay.begin(),bloomDay.end());

        int mid;
        while(l<r){
            mid = (l+r)>>1;
            if(fun(bloomDay,m,k,mid)) r = mid;
            else l = mid+1;
        }

        return l;
    }
};