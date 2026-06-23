class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        long long l = (long long)pow(10 , (intLength+1)/2 -1);
        long long r = (long long)(pow(10 , (intLength+1)/2) - 1);
        for(int q: queries){
            if(q<=r-l+1){
                string lh = to_string(l+q-1);
                string rh = lh;
                reverse(rh.begin(),rh.end());
                if(intLength & 1) rh = rh.substr(1);
                ans.push_back(stoll(lh+rh));
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};