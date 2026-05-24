class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int i=0, j=0;
        int maxlen = 0;
        while(j<s.size()){
            if(hash[s[j]]>=i && hash[s[j]]!=-1){
                i = hash[s[j]]+1;
            }
            maxlen=max(maxlen,j-i+1);
            hash[s[j]] = j;
            j++;
        }
        return maxlen;
    }
};