class KthLargest {
private:
    int gk; // Global copy of k
    // Min-heap: stores the k largest elements seen so far
    priority_queue<int, vector<int>, greater<int>> pq; 

public:
    KthLargest(int k, vector<int>& nums) {
        gk = k;
        
        // Push all initial elements into our min-heap
        for (int num : nums) {
            pq.push(num);
            // If the heap grows larger than k, discard the smallest element
            if (pq.size() > gk) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        // Push the new value into the streaming heap
        pq.push(val);
        
        // If we exceed size k, remove the smallest element
        if (pq.size() > gk) {
            pq.pop();
        }
        
        // The top of our min-heap of size k is always the kth largest element
        return pq.top();
    }
};