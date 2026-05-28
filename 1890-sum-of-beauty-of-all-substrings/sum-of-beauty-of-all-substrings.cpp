class Solution {
public:
    int beauty(string& s,int i,int j){
        vector<int> hash(26,0);
        for(int k =i;k<=j;k++){
            hash[s[k]-'a']++;
        }
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i=0;i<26;i++){
            if(hash[i]==0) continue;
            else{
                mx = max(mx,hash[i]);
                mn = min(mn,hash[i]);
            }
        }
        return mx - mn;
    }
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                ans+=beauty(s,i,j);
            }
        }
        return ans;
    }
};