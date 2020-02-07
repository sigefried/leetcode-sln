class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    map<int,int> cnt;
    bool book(int start, int end) {
        cnt[start]++;
        cnt[end]--;
        int active = 0;
        for(auto it : cnt) {
            active += it.second;
            if(active >= 3) {
                cnt[start]--;
                cnt[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalXendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */