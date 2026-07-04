class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char c: t) mp[c]++;
        int startidx = -1;
        int minlen = INT_MAX;
        int l = 0, r = 0;
        int count = 0;
        while(r<s.size()){
            if(mp[s[r]]>0) count++;
            mp[s[r]]--;
            while(count==t.size() && l<=r){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    startidx = l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        if(startidx == -1) return "";
        string ans =  s.substr(startidx,minlen);
        return ans;
    }
};