class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0;
        int count=0;
        for(char c:s){
            if(c=='(') count++;
            if(c==')') count--;
            maxdepth = max(maxdepth,count);
        }
        return maxdepth;
    }
};