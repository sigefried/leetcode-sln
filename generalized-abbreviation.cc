class Solution {
public:
    vector<string> ret;
    vector<string> generateAbbreviations(string word) {
        string tmp;
        dfs(word, tmp, 0, 0);
        return ret;
    }
    
    void dfs(string word, string tmp, int i, bool prevNum) {
        if(i == word.size()) {
            ret.push_back(tmp);
            return;
        }
        dfs(word, tmp + word[i], i + 1, false);
        if(!prevNum) {
            for(int len = 1; i + len <= word.size(); ++len) {
                dfs(word,tmp + to_string(len), i + len, true);
            }
        }
    }
};