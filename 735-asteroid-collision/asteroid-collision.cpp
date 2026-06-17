class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(int a:asteroids){
            if(a<0 && !st.empty() && st.top()>0){
                    bool push = true;
                    while(!st.empty() && st.top()>0){
                        if(st.top()<abs(a)){
                            st.pop();
                        }
                        else if(abs(a)==st.top()){
                            st.pop();
                            push = false;
                            break;
                        }
                        else{
                            push = false;
                            break;
                        }
                    }
                    if(push) st.push(a);
                
            }
            else st.push(a);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};