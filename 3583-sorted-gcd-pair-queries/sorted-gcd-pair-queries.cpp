class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(),nums.end());

        vector<int> freq(mx+1,0);
        vector<long long> div(mx+1,0);

        for(int x: nums) freq[x]++;
        for(int i = 1;i<=mx;i++){
            for(int j = i;j<=mx;j+=i){
                div[i] += freq[j];
            }
        }
        vector<long long> exact(mx+1,0);
        for(int i = mx;i>=1;i--){
            exact[i] = div[i]*(div[i]-1)/2;
            for(int j = 2*i;j<=mx;j+=i){
                exact[i] -= exact[j];
            }
        }
        for(int i = 1;i<=mx;i++) exact[i] += exact[i-1];

        vector<int> ans;
        for(long long q: queries){
            int g = lower_bound(exact.begin()+1,exact.end(),q+1) - exact.begin();
            ans.push_back(g);
        }
        return ans;
    }
};