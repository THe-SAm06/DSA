class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen=0, maxfreq=0;
        vector<int> hash(26,0);
        int l=0,r=0;
        for(int a : s){
            hash[s[r]-'A']++;
            maxfreq = max(maxfreq,hash[s[r]-'A']);
            if(r-l+1-maxfreq<=k){
                maxlen = max(maxlen,r-l+1);
            }
            if(r-l+1-maxfreq>k){
                hash[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};