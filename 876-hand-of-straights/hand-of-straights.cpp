class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize) return false;
        map<int,int> mp;
        for(int a:hand){
            mp[a]++;
        }
        int c;
        for(auto [card,count]:mp){
            while(count>0){
                for(int next = card;next<card+groupSize;next++){
                    if(mp[next]==0) return false;
                    mp[next]--;
                }
                count--;
            }
        }
        return true;
    }
};