/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> ret;
        map<int, int> tl;
        int n = schedule.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < schedule[i].size(); ++j) {
                tl[schedule[i][j].start]++;
                tl[schedule[i][j].end]--;
            }
        }
        
        int active = 0;
        for(auto p : tl) {
            active += p.second;
            if(!active) ret.push_back(Interval(p.first, 0));
            if(active && !ret.empty() && ret.back().end == 0) {
                ret.back().end = p.first;
            }
        }
        if(!ret.empty()) ret.pop_back();
        return ret;
    }
};