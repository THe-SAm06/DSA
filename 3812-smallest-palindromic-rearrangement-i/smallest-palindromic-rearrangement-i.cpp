class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        map<char,int> mp;
        for(char &c:s) mp[c]++;

        string mid = "";

        string left = "";

        for(auto &[c,count]: mp){
            left += string(count/2,c);
            if(count&1) mid = c;
        }
        string right = left;
        reverse(right.begin(),right.end());
        return left+mid+right;
    }
};