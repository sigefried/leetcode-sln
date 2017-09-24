class LRUCache {
public:
    int cap;
    list<pair<int,int>> store;
    unordered_map<int, pair<list<pair<int,int>>::iterator, int>> m;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.count(key) == 0) {
            return -1;
        }
        int ret = m[key].second;
        update(key, ret);
        return ret;
    }
    
    void update(int key, int value) {
        auto iter = m[key].first;
        store.erase(iter);
        store.push_front({key,value});
        m[key] = {store.begin(), value};
    }
    
    void put(int key, int value) {
        if (store.size() == cap && m.count(key) == 0) {
            int old_key = store.back().first;
            store.pop_back();
            m.erase(old_key);
        }
        if (m.count(key) == 0) {
            store.push_front({key, value});
            m[key] = {store.begin(), value};
        } else {
            update(key, value);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */