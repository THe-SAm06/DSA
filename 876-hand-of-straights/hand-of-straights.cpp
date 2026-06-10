class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());

while(!hand.empty()) {

    int last = hand[0];
    hand.erase(hand.begin());

    int cnt = 1;

    int i = 0;

    while(cnt < groupSize) {

        while(i < hand.size() && hand[i] <= last)
            i++;

        if(i == hand.size() || hand[i] != last + 1)
            return false;

        last = hand[i];
        hand.erase(hand.begin() + i);

        cnt++;
    }
}

return true;
    }
};