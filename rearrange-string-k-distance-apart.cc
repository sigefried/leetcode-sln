class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k == 0) return s;
        unordered_map<char, int> charCount;
        for(auto ch : s) {
            charCount[ch]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto it : charCount) {
            pq.push({it.second, it.first});
        }
        int n = s.size();
        string ret = "";
        queue<pair<int,char>> tmp;
        for(int i = 0; i < n; ++i) {
            int rem = n - ret.size();
            int len = min(k, rem);
            for(int j  = 0; j < len; ++j) {
                if(pq.size() == 0) return "";
                auto cur = pq.top(); pq.pop();
                ret.push_back(cur.second);
                cur.first--;
                
                if(cur.first >0)
                    tmp.push(cur);
            }
            while(!tmp.empty()) {
                pq.push(tmp.front()); tmp.pop();
            }
        }
        return ret;
    }
};