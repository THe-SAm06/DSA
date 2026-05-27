class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minl=INT_MAX;
        for(int i=0;i<strs.size();i++){
            minl=min(minl,(int)strs[i].size());
        }
        string str="";
        for(int i=0;i<minl;i++){
            bool is=true;
            int j=0;
            for(;j<strs.size()-1;j++){
                if(strs[j][i]!=strs[j+1][i]){
                    is=false;
                    break;
                }
            }
            if(is) str+=strs[j][i];
            else break;
        }
        return str;
    }
};