class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, set<char>> mp;
        map<char, int> indegree;
        string ans;
        
        if(words.size() == 0) return ans;
        
        for(auto s: words){
            for(auto c: s) {
                indegree[c] = 0;
            }
        }
        
        for(int i = 0; i < words.size() - 1; ++i) {
            string cur=words[i];
            string next=words[i+1];
            int len = min(cur.size(), next.size());
            
            for(int j = 0; j < len; ++j) {
                char c1 = cur[j];
                char c2 = next[j];
                if(c1 != c2) {
                    if(mp[c1].count(c2) == 0) {
                        mp[c1].insert(c2);
                        indegree[c2]++;
                    }
                    break;
                }
            }
        }
        
        
        queue<char> q;
        
        for(auto it : indegree) {
            if(it.second == 0) {
                q.push(it.first);
            }
        }
        
        while(!q.empty()) {
            char cur = q.front(); q.pop();
            ans.push_back(cur);
            if(mp.count(cur) > 0) {
                for(auto n : mp[cur]) {
                    indegree[n]--;
                    if(indegree[n] == 0) {
                        q.push(n);
                    }
                }
            }
        }
        //cout << ans << endl;
        return ans.size() == indegree.size() ? ans : "";
    }
};