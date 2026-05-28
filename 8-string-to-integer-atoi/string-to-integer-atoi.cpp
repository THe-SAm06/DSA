class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' ') i++;
        s=s.substr(i);
        int sign =+1;
        if(s[0]=='-') sign=-1;
        i = (s[0]=='+' || s[0]=='-')?1:0;
        long long ans=0;
        while(i<s.size() && isdigit(s[i])){
            ans = ans*10 + (s[i]-'0');
            if(sign==-1 && ans*sign<INT_MIN) return INT_MIN;
            if(sign==+1 && ans*sign>INT_MAX) return INT_MAX;
            i++;
        }
        return (int)(ans*sign);
    }
};