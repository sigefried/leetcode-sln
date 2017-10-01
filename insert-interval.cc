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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        if (intervals.size() == 0) {
            ret.push_back(newInterval);
            return ret;
        }
        int left_bar = 0;
        for (; left_bar < intervals.size() && intervals[left_bar].end < newInterval.start; ++left_bar);
        int right_bar = left_bar;
        for (;right_bar < intervals.size() && intervals[right_bar].start <= newInterval.end; ++right_bar);
        int i = 0;
        for (; i < left_bar; ++i) {
            ret.push_back(intervals[i]);
        }
        for (; i < right_bar;++i) {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
        ret.push_back(newInterval);
        
        for (;i < intervals.size();++i) {
            ret.push_back(intervals[i]);
        }
        return ret;
    }
};