class StockSpanner {
public:
    stack<int> st;
    int i =0;
    vector<int> arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans;
        while(!st.empty() && arr[st.top()]<=price){
                st.pop();
            }
            ans = i-(st.empty()?-1:st.top());
            st.push(i);
            arr.push_back(price);
            i++;
            return ans;
        }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */