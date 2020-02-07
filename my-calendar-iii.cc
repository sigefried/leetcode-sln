class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int,int> cnt;
    int book(int start, int end) {
        cnt[start]++;
        cnt[end]--;
        int active = 0;
        int ans = 0;
        for(auto it : cnt) {
            active += it.second;
            if(active > ans) {
                ans = active;
            }
        }
        return ans;        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */