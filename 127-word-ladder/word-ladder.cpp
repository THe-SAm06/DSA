class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end()) return 0;
        int s = beginWord.size();
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            auto [word,steps] = q.front();
            q.pop();
            if(word == endWord) return steps;

            for(int i =0;i<s;i++){
                char og = word[i];
                for(char c='a';c<='z';c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }
};