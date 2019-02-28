class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        if (n == 0) return T;
        vector<int> ret(n, 0);
        stack<int> indicies;
        for (int i = n - 1; i >= 0; --i) {
            int cur = T[i];
            while(!indicies.empty() && cur >= T[indicies.top()]) indicies.pop();
            ret[i] = indicies.empty() ? 0 : indicies.top() - i;
            indicies.push(i);
        }
        return ret;
    }
};