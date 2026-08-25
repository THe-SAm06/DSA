class LRUCache {
public:
    list<int> dll;
    unordered_map<int,pair<list<int>::iterator,int>> mp;

    int c;

    LRUCache(int capacity) : c{capacity} {
        
    }

    void fun(int k){
        dll.erase(mp[k].first);
        dll.push_front(k);
        mp[k].first = dll.begin();
    }
    
    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }
        fun(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key].second = value;
            fun(key);
        }
        else{
            if(c <= 0){
                int k = dll.back();
                mp.erase(k);
                dll.pop_back();
                c++;
            }
            dll.push_front(key);
            mp[key] = {dll.begin(),value};
            c--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */