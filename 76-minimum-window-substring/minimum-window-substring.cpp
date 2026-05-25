class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hash;
        for(char a:t){
            hash[a]++;
        }
        int l=0,r=0,minlen=INT_MAX;
        int count =0;
        int i=-1,j=-1;
        while(r<s.size()){
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;
            while(count==t.size()){
                if(r-l+1<minlen){
                    minlen =r-l+1;
                    i=l, j=r;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        if(i==-1) return "";
        string str;
        for(int k=i;k<=j;k++){
            str+=s[k];
        }
        return str;
    }
};