class Solution {
public:
    void addone(string& s){
        for(int i = s.size()-1;i>=0;i--){
            if(s[i] == '0'){
                s[i] = '1';
                return;
            }
            else s[i] = '0';
        }
        s = '1' + s;
    }
    int numSteps(string s) {
        int ops = 0;
        while(s.size()>1){
            if(s.back() == '1'){
                addone(s);
            }
            else s.pop_back();
            ops++;
        }
        return ops;
    }
};