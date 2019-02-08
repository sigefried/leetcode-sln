class ExamRoom {
public:
    int N;
    set<int> students;
    
    ExamRoom(int N) : N(N) {
        
    }
    
    int seat() {
        int pos = 0;
        if(students.size() > 0) {
            //check first
            int dist = *students.begin();
            int prev = -1;
            for(auto cur : students) {
                if(prev >= 0) {
                    int d = (cur - prev) / 2;
                    if(d > dist) {
                        pos = prev + d;
                        dist = d;
                        
                    }
                }
                prev = cur;
            }
            // check last
            if (N - 1 - *(--students.end()) > dist) {
                pos = N - 1;
            }
        }
        
        // empty
        students.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        students.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */