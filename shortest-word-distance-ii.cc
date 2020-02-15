class WordDistance {
public:
    unordered_map<string, vector<int>> wm;
    
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i) {
            wm[words[i]].push_back(i);
        }
    }
    
    
    
    int shortest(string word1, string word2) {
        int i = 0, j = 0, ans = INT_MAX;
        while(i < wm[word1].size() && j < wm[word2].size()) {
            ans = min(ans, abs(wm[word1][i] - wm[word2][j]));
            wm[word1][i]<wm[word2][j]?i++:j++;
        }
        
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */