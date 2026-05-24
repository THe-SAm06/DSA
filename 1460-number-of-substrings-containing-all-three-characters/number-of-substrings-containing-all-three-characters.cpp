class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> hash;
        int i=0, j=0, ans=0;
        while(j<s.size()){
            hash[s[j]]++;
            while(hash.size()==3){
                hash[s[i]]--;
                if(hash[s[i]]==0) hash.erase(s[i]);
                i++;
                ans+=s.size()-j;
            }
            j++;
        }
        return ans;
    }
};