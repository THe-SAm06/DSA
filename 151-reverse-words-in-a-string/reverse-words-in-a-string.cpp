class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        int j = s.size() - 1;

        while (i <= j && s[j] == ' ') j--;
        while (i <= j && s[i] == ' ') i++;

        string str = "";

        while (i <= j) {
            if (s[i] == ' ') {
                if (!str.empty()) {
                    words.push_back(str);
                    str = "";
                }
            } 
            else {
                str += s[i];
            }
            i++;
        }

        words.push_back(str);

        str = "";

        for (int k = words.size() - 1; k >= 0; k--) {
            str += words[k];
            if (k != 0) str += " ";
        }

        return str;
    }
};