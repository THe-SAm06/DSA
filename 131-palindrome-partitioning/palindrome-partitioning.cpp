class Solution {
public:
    bool ispal(string s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    void back(vector<vector<string>> &strin,vector<string> &str,string s){
        if(s.size()==0){
            strin.push_back(str);
            return;
        }
        for(int i=0;i<s.size();i++){
            string p=s.substr(0,i+1);
            if(ispal(p)){
                str.push_back(p);
                back(strin,str,s.substr(i+1));
                str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> strin;
        vector<string> str;
        back(strin,str,s);
        return strin;
    }
};