class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> last(26,-1);
        vector<bool> vis(26,false);

        for(int i = 0;i<s.size();i++) last[s[i]-'a'] = i;

        for(int i = 0;i<s.size();i++){

            if(vis[s[i]-'a']) continue;
            while(!st.empty() && s[i]<st.top() && i<last[st.top()-'a']){
                vis[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a'] = true;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};