class LFUCache {
public:
    int cap;
    int size;
    int minFreq;
    unordered_map<int, pair<int, int>> m;  // k-> {val, freq}
    unordered_map<int, list<int>::iterator> mIter;  // key -> key place
    unordered_map<int, list<int>>  fm; // freq -> key list

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;        
    }
    
    int get(int key) {
        if(m.count(key) == 0) return -1;
        fm[m[key].second].erase(mIter[key]);
        m[key].second++;
        fm[m[key].second].push_back(key);
        mIter[key]=prev(fm[m[key].second].end());
        if(fm[minFreq].size() == 0) {
            minFreq++;
        }
        
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(cap <= 0) return;
        
        int existValue = get(key);
        if(existValue != -1) {
            m[key].first = value;
            return;
        }
        
        if(size >= cap) {
            int old_key = fm[minFreq].front();
            m.erase(old_key); // delete key
            mIter.erase(old_key);
            fm[minFreq].pop_front();
        }
        
        m[key] = {value, 1};
        fm[1].push_back(key);
        mIter[key] = prev(fm[1].end());
        minFreq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */