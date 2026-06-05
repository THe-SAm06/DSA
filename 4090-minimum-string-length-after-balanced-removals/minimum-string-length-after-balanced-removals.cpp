class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]!=st.top()){
                st.pop();
            }
            else st.push(s[i]);
        }
        return st.size();
    }
};