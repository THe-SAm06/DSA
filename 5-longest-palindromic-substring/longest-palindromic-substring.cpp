class Solution {
public:
    bool ispal(string& s,int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++, j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxlen = 0;
        int start;
        for(int i=0;i<s.size();i++){
            for(int j =i;j<s.size();j++){
                if(ispal(s,i,j) && maxlen<j-i+1){
                    start = i;
                    maxlen = j-i+1;
                }
            }
        }
        return s.substr(start,maxlen);
    }
};