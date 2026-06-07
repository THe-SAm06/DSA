class Solution {
public:
    void recur(int n, vector<string>& ans,string s,int open,int close){
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }
        if(close>open) return ;
        if(open<n) recur(n,ans,s+'(',open+1,close);
        if(close<open) recur(n,ans,s+')',open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur(n,ans,"",0,0);
        return ans;
    }
};