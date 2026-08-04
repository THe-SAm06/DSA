class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;

        unordered_set<int> st;
        for(int &a: nums){
            mn = min(mn,a);
            mx = max(mx,a);
            st.insert(a);
        }

        vector<int> ans;

        for(int i = mn+1;i<mx;i++){
            if(!st.count(i)) ans.push_back(i);
        }

        return ans;
    }
};