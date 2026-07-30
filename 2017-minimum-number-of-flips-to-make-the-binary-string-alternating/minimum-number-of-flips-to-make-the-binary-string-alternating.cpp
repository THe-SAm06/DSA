class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        string s1 = "1";
        string s2 = "0";
        for(int i = 1;i<2*n;i++){
            s1.push_back(s1.back()=='1'?'0':'1');
            s2.push_back(s2.back()=='1'?'0':'1');
        }

        int r = 0, l = 0;
        
        int ops = INT_MAX;
        int f1 = 0;
        int f2 = 0;
        while(r<2*n){
            if(s1[r] != s[r]) f1++;
            if(s2[r] != s[r]) f2++;
            while(r-l+1>n){
                if(s1[l] != s[l]) f1--;
                if(s2[l] != s[l]) f2--;
                l++;
            }
            if(r-l+1 == n){
                ops = min(ops,min(f1,f2));
            }
            r++;
        }
        return ops;
    }
};