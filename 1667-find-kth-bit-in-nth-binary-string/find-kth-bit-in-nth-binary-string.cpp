class Solution {
public:
    string fun(string s){
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1') s[i] = '0';
            else s[i] = '1';
        }
        reverse(s.begin(),s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 2;i<=n;i++){
            string s1 = fun(s);
            s.append("1");
            s.append(s1);
        }
        return s[k-1];
    }
};