class Solution {
private:
    void dfs(string& bw,string& ew,vector<vector<string>>& ans,vector<string>& path,unordered_map<string,int>& level){
        
        if(ew == bw){
            reverse(path.begin(),path.end());
            ans.push_back(path);
            reverse(path.begin(),path.end());
            return;
        }

        int steps = level[ew];
        for(int i = 0;i<ew.size();i++){
                char og = ew[i];
                for(char c='a'; c<='z'; c++){
                    ew[i] = c;
                    if(level[ew]+1 == steps){
                        path.push_back(ew);
                        dfs(bw,ew,ans,path,level);
                        path.pop_back();
                    }
                }
                ew[i] = og;
            }
        return;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end()) return {};
        unordered_map<string,int> level;

        queue<string> q;
        q.emplace(beginWord);
        level[beginWord] = 1;
        st.erase(beginWord);

        while(!q.empty()){
            auto word= q.front();
            q.pop();
            if(word==endWord) break;
            int steps = level[word];
            for(int i = 0;i<word.size();i++){
                char og = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){   // word is there in wordList;
                        level[word] = steps+1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = og;
            }
        }
        vector<vector<string>> ans;
        vector<string> path;
        path.push_back(endWord);
        dfs(beginWord,endWord,ans,path,level);
        return ans;
    }
};