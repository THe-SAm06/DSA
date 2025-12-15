class Solution {
public:
    void recurse(string &digits,int str,vector<string> &v,string &s,unordered_map<int,string> &mp){
        if(s.size()==digits.size()){
            v.push_back(s);
            return;
        }
        for(int i=0;i<mp[digits[str]-'0'].size();i++){
            s.push_back(mp[digits[str]-'0'][i]);
            recurse(digits,str+1,v,s,mp);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        vector<string> v;
        string s;
        recurse(digits,0,v,s,mp);
        return v;
    }
};