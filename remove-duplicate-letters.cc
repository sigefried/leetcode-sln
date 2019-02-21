class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> occurs;
        for(auto ch : s) {
            occurs[ch]++;
        }
        
        string stk;
        unordered_map<char, bool> visited;
        for(auto ch : s) {
            while(!stk.empty() && !visited[ch] && stk.back() >= ch && occurs[stk.back()] > 1) {                                
                occurs[stk.back()]--;
                visited[stk.back()] = false;
                stk.pop_back();
            }
            if(!visited[ch]) {
                stk.push_back(ch);
                visited[ch] = true;
            } else {
                occurs[ch]--;
            }
        }
        return stk;
    }
};