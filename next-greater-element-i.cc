class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> m;
        for(auto n : nums) {
            while(stk.size() && stk.top() < n) {
                m[stk.top()] = n;
                stk.pop();
            }
            stk.push(n);
        }
        
        vector<int> ret;
        
        for(auto n : findNums) {
            ret.push_back(m.count(n) ? m[n] : -1);
        }
        return ret;
    }
};