class Solution {
public:
    bool fun(vector<int>& b,int m,int k,int v){
        int cnt = 0;
        int count=0;
        for(int i =0;i<b.size();i++){
            if(b[i]<=v){
                cnt++;
            }
            else{
                count+=cnt/k;
                cnt=0;
            }
        }
        count += cnt / k; 
        return count>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mn = *min_element(bloomDay.begin(), bloomDay.end());
        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        if(m>bloomDay.size()/k) return -1;
        while(mn<mx){
            int mid = mn+(mx-mn)/2;
            if(fun(bloomDay,m,k,mid)) mx = mid;
            else mn = mid+1;
        }
        return mn;
    }
};