class Solution {
public:
    int minLengthAfterRemovals(string s) {
        char last = s[0];
        int count = 1;
        for(int i=1;i<s.size();i++){
            if(count==0){
                last = s[i];
                count = 1;
            }
            else if(s[i]==last) count++;
            else{
                count--;
            }
        }
        return count;
    }
};