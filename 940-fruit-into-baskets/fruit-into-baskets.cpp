class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> type;
        int i=0, j=0;
        int maxlen=0;
        while(j<fruits.size()){
            type[fruits[j]]++;
            if(type.size()>2){
                while(type.size()>2){
                    type[fruits[i]]--;
                    if(type[fruits[i]]==0){
                        type.erase(fruits[i]);
                    }
                    i++;
                }
            }
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};