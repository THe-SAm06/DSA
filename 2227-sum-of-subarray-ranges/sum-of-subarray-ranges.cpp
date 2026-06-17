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
    vector<int> getpge(vector<int>& arr){
        int n = arr.size();
        vector<int> pge(n);
        stack<int> st;
        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            pge[i] = (st.empty()?-1:st.top());
            st.push(i);
        }
        return pge;
    }
    vector<int> getnge(vector<int>& arr){
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            nge[i] = (st.empty()?n:st.top());
            st.push(i);
        }
        return nge;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = getpse(arr);
        vector<int> nse = getnse(arr);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 1LL * arr[i] * (i - pse[i]) * (nse[i] - i);
            ans = (ans + sum) ;
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge = getpge(arr);
        vector<int> nge = getnge(arr);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 1LL * arr[i] * (i - pge[i]) * (nge[i] - i);
            ans = (ans + sum);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
       return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};