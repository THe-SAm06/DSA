class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int count = 0;
        int k = 1;
        int pushes = 0;
        for(int& a:freq){
            // cout<<a<<' ';
            if(!a) continue;
            count++;
            // cout<<count<<" "<<k<<'n';
            pushes += k*a;
            if(count % 8 == 0 && count!=0){
                k++;
            }
        }
        return pushes;
    }
};