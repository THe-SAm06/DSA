class Solution {
public:
    vector<int> getpse(vector<int>& arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            pse[i] = (st.empty()?-1:st.top());
            st.push(i);
        }
        return pse;
    }
    vector<int> getnse(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            nse[i] = (st.empty()?n:st.top());
            st.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = getpse(arr);
        vector<int> nse = getnse(arr);
        const long long MOD = 1000000007LL;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 1LL * arr[i] * (i - pse[i]) * (nse[i] - i);
            ans = (ans + sum) % MOD;
        }
        return (int)ans;
    }
};