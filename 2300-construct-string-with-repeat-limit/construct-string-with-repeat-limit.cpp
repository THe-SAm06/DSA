class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26);

        for(char c:s) freq[c-'a']++;

        stack<pair<char,int>> st;

        string ans ="";

        for(int i = 0;i<26;i++){
            if(freq[i]) st.push({i+'a',freq[i]});
        }

        while(!st.empty()){
            auto [c,count] = st.top();
            st.pop();

            while(count>0){
                if(count>repeatLimit){
                    ans += string(repeatLimit,c);
                    count -= repeatLimit;
                    if(st.empty()) break;
                    auto [nextc,c1] = st.top();
                    st.pop();
                    ans += nextc;
                    if(c1-1>0) st.push({nextc,c1-1});
                }
                else{
                    ans += string(count,c);
                    count = 0;
                }
            }
        }

        return ans;
    }
};