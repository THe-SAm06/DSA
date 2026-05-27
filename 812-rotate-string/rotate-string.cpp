class Solution {
public:
    string shift(string s){
        char first = s[0];
        for(int i=0;i<s.size()-1;i++){
            s[i]=s[i+1];
        }
        s[s.size()-1]=first;
        return s;
    }
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            if(shift(s)==goal) return true;
            s=shift(s);
        }
        return false;
    }
};