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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) return 0;
        int ret = 0;
        vector<pair<int,int>> tmp;
        for (auto & interval : intervals) {
            tmp.push_back({interval.start, 1});
            tmp.push_back({interval.end, -1});
        }
        sort(tmp.begin(), tmp.end(), [] (pair<int,int> &a, pair<int,int> &b) {
           if (a.first == b.first) {
               return a.second < b.second;
           }
           return a.first < b.first; 
        });
        int cur = 0;
        for (auto it : tmp) {
            cur = cur + it.second;
            ret = max(ret, cur);
        }
        return ret;
    }
};