class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string str="";
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        while(!pq.empty()){
            auto [freq,s] = pq.top();
            pq.pop();
            if(str.size()>1 && str[str.size()-1]==str[str.size()-2] && str[str.size()-1]==s){
                if(pq.size()==0) break;
                auto [f2,s2] = pq.top();
                pq.pop();
                str+=s2;
                f2--;
                if(f2>0) pq.push({f2,s2});
            }
            else{
                str+=s;
                freq--;
            }
            if(freq>0) pq.push({freq,s});
        }
        return str;
    }
};