class RecentCounter {
    queue<int> q;
    int count;
public:
    RecentCounter() : count{0} {
        
    }
    
    int ping(int t) {
        int l = t-3000;
        while(!q.empty() && q.front() < l){
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */