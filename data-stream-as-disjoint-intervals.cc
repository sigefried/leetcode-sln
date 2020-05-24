class SummaryRanges {
public:
    map<int,int> memo;
    /** Initialize your data structure here. */
    SummaryRanges() {
        memo[INT_MIN] = INT_MIN;
    }
    
    void addNum(int val) {
        auto it = memo.upper_bound(val);
        auto prv = prev(it); 
        if(prv->first <= val && prv->second >= val) return;
        
        bool found_nxt = it != memo.end() && it->first == val+1;
        if(found_nxt) {
            memo[val] = it->second;
        }
        
        bool found_prv = prv->second + 1 == val;
        
        if(found_prv) {
            if(found_nxt) {
                prv->second = it->second;
                memo.erase(prev(it));
            } else {
                prv->second = val;
            }
        }
        
        if(!found_nxt && !found_prv) {
            memo[val] = val;
        }
        if(found_nxt) {
            memo.erase(it);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for (auto &elm: memo) {
            if (elm.first == INT_MIN)
                continue;
            ret.push_back({elm.first, elm.second});
        }
        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */