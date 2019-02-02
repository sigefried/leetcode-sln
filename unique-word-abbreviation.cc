class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> abbrDict;
    ValidWordAbbr(vector<string> dictionary) {
        for(auto s : dictionary) {
            string key = toAbbr(s);
            abbrDict[key].insert(s);
        }
    }
    
    bool isUnique(string word) {
        string k = toAbbr(word);
        unordered_set<string> t = abbrDict[k];
        return t.size() == 0 || (t.size() == 1 && t.count(word));
    }
    
    string toAbbr(string s) {
        if(s.size() <= 2) {
            return s;
        }
        int n = s.size();
        return s[0] + to_string(n-2) + s[n-1];
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */