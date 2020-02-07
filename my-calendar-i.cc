class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    
    map<int, int> m;
    bool book(int start, int end) {
        auto next = m.lower_bound(start);
        if(next != m.end() && next->first < end) return false;
        if(next != m.begin() && (--next)->second > start) return false;
        m[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */