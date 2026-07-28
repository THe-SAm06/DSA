class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        for(char &c:s) freq[c-'a']++;

        string mid = "";

        string left = "";

        for(int i = 0;i<26;i++){
            if(!freq[i]) continue;
            left += string(freq[i]/2,i+'a');
            if(freq[i] & 1) mid = i+'a';
        }
        string right = left;
        reverse(right.begin(),right.end());
        return left+mid+right;
    }
};