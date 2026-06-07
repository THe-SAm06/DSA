class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        map<pair<int,int>,int> mp;
        int i =0;
        int l , r;
        while(i<s.size()){
            if(s[i]=='1'){
                l = i;
                while(s[i]=='1'){
                    i++;
                }
                r = i-1;
                mp[{l,r}] = 1;
            }
            else i++;
        }
        long long sum = 0;
        for(auto it: mp){
            int l = it.first.first;
            int r = it.first.second;
            if(l==0){
                for(int i=l;i<=r;i++){
                    sum += (long long)nums[i];
                }
            }
            else{
                if(l>0){
                    int mn = nums[l-1];
                    for(int i =l-1;i<=r;i++){
                        mn = min(mn,nums[i]);
                        sum+= (long long)nums[i];
                    }
                    sum -= (long long)mn;
                }
            }
        }
        return sum;
    }
};