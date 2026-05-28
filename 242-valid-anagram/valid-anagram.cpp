class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash;
        for(char c: s){
            hash[c]++;
        }
        for(char c:t){
            hash[c]--;
            if(hash[c]==0) hash.erase(c);
        }
        return hash.size()==0;
    }
};