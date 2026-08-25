class LFUCache {
public:
    int c;

    unordered_map<int,pair<list<int>::iterator,int>> mp;
    unordered_map<int,list<int>> freq;
    unordered_map<int,int> f;

    int minf = 1;

    LFUCache(int capacity) : c{capacity} {
    
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        int fr = f[key];
        f[key] = fr+1;

        freq[fr].erase(mp[key].first);
        if(fr == minf and freq[fr].empty()) minf++;

        freq[fr+1].push_front(key);

        mp[key].first = freq[fr+1].begin();

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key].second = value;
            get(key);
        }
        else{
            if(c <= 0){
                int k = freq[minf].back();
                mp.erase(k);
                freq[minf].pop_back();
                c++;
            }
            f[key] = 1;
            freq[1].push_front(key);
            mp[key] = {freq[1].begin(),value};
            minf = 1;
            c--;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */