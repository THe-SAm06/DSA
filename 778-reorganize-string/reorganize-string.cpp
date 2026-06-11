class Solution {
public:
    string reorganizeString(string s) {
        string str ="";
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        priority_queue<pair<int,char>> pq;
        for(int i =25;i>=0;i--){
            if(freq[i]==0) continue;
            pq.push({freq[i],i+'a'});
        }
        while(!pq.empty()){
            auto [freq,s1] = pq.top();
            pq.pop();
            if(str.size()>0 && str[str.size()-1]==s1){
                if(pq.empty()) return "";
                auto [freq2,s2] = pq.top();
                pq.pop();
                str+=s2;
                freq2--;
                if(freq2>0) pq.push({freq2,s2});
            }
            else{
                str+=s1;
                freq--;
            }
            if(freq) pq.emplace(freq,s1);
        }
        return str;
    }
};