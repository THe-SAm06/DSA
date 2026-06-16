class MinStack {
public:
    stack<long long> st;
    long long min_val = INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            min_val = value;
        }
        else{
            if(value<min_val){
                long long val = value;
                st.push((2*val-min_val));
                min_val = value;
            }
            else st.push(value);
        }
    }
    
    void pop() {
        if(st.top()<min_val){
            min_val = 2*min_val-st.top();
            st.pop();
        }
        else st.pop();
    }
    
    int top() {
        if(st.top()<min_val){
            return min_val;
        }
        else return st.top();
    }
    
    int getMin() {
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */