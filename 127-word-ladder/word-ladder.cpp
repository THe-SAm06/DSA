class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isthere = false;
        for(string s: wordList){
            if(s==endWord){
                isthere = true;
                break;
            }
        }
        if(!isthere) return 0;

        int n = wordList.size();
        int s = beginWord.size();
        unordered_map<string,vector<string>> adj;
        int count;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                count = 0;
                for(int k =0;k<s;k++){
                    if(wordList[i][k] != wordList[j][k]) count++;
                    if(count > 1){
                        break;
                    }
                }
                if(count == 1){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for(auto [str, vec]:adj){
            cout<<str<<": ";
            for(auto s:vec){
                cout<<s<<" ";
            }
            cout<<"\n";
        }
        for (int i = 0; i < n; i++) {
            int diff = 0;
            for (int j = 0; j < s; j++) {
                if (beginWord[j] != wordList[i][j]) {
                    diff++;
                    if (diff > 1) break;
                }
            }

            if (diff == 1) {
                adj[beginWord].push_back(wordList[i]);
            }
        }
        queue<pair<string,int>> q;
        unordered_map<string,int> mp;
        for(auto s: wordList) mp[s] = INT_MAX;
        q.push({beginWord,0});
        while(!q.empty()){
            auto [str,dis] = q.front();
            cout<<str<<"\n";
            q.pop();
            if(str == endWord) return dis+1;
            mp[str] = dis;

            for(auto v: adj[str]){
                if(dis+1<mp[v]) q.push({v,dis+1});
            }
        }
        return 0;
    }
};