class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hash;
        for(char c: s) hash[c]++;
        vector<pair<char,int>> freq(hash.begin(),hash.end());
        sort(freq.begin(),freq.end(),[](pair<char,int> &a,pair<char,int> &b){
            return a.second>b.second;
        });
        string str="";
        for(auto it:freq){
            str.append(it.second,it.first);
        }
        return str;
    }
};