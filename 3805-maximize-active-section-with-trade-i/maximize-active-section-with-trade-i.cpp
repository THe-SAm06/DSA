class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> blocks;
        int i = 0;
        int count = 0;
        int count1 = 0;
        while(i<s.size()){
            if(s[i] == '0'){
                count = 0;
                while(i<s.size() && s[i] == '0'){
                    count++;
                    i++;
                }
                blocks.push_back(count);
            }
            else{
                count1++;
                i++;
            }
        }
        if(blocks.size() == 1) return count1;
        int mx = 0;
        for(int i = 1;i<blocks.size();i++){
            mx = max(mx,blocks[i]+blocks[i-1]);
        }
        return mx+count1;
    }
};