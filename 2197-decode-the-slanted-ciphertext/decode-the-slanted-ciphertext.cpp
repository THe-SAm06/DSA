class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n/rows;
        string ans = "";
        int i =0;
        while(i<cols){
            int k = 0;
            for(int j = i;k<rows && j<n;j+=cols+1){
                ans += encodedText[j];
                k++;
            }
            i++;
        }
        while (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};