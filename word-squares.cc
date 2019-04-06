class Solution {
public:
    unordered_map<string, vector<string>> prefix;
    int n;
    vector<vector<string>> ret;
    vector<string> square;
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words[0].size();
        for(auto word : words) {
            for(int i = 0; i < n; ++i) {
                prefix[word.substr(0, i)].push_back(word);
            }
        }
        square.resize(n);
        dfs(0);
        return ret;
    }
    
    void dfs(int i) {
        if(i == n) {
            //for(auto w : square) cout << w;
            ret.push_back(square);
            return;
        }
        
        string pre = "";
        for(int k = 0; k < i; ++k) {
            pre += square[k][i];
        }
        for(auto w : prefix[pre]) {
            square[i] = w;
            dfs(i + 1);
        }
    }
};