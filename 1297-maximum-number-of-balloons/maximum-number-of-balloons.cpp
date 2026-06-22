class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mp;
        for(char c: text){
            if(c=='b' || c=='a' || c=='l' || c=='l' || c=='o' || c=='o' || c=='n'){
                mp[c]++;
            }
        }
        mp['l'] /= 2;
        if(mp['l']==0) mp.erase('l');
        mp['o'] /= 2;
        if(mp['l']==0) mp.erase('l');
        if(mp.size()<5) return 0;
        int mn = INT_MAX;
        for(auto it:mp) mn = min(mn,it.second);
        return mn;
    }
};