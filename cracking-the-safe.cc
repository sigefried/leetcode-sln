// dfs
class Solution {
public:
    unordered_set<string> visited;
    int total;
    int n;
    int k;
    string crackSafe(int n, int k)  {
        this->n = n;
        this->k = k;
        total = pow(k,n);
        string ret(n,'0');
       // cout << ret;
        visited.insert(ret);
        dfs(ret);
        return ret;
    }
    
    bool dfs(string &ret) {
        if(visited.size() == total) {
            return true;
        }
        string prefix;
        
        //cout << ret.size() << "," << n << " " << ret << endl;
        prefix = ret.substr(ret.size() - n + 1);
       // cout << prefix << endl;
        for(int i = 0; i < k; ++i) {
            string next = prefix + to_string(i);
            if(visited.count(next) == 0) {
                visited.insert(next);
                ret.push_back('0'+i);
                if(dfs(ret)) {
                    return true;
                }
                ret.pop_back();
                visited.erase(next);
            }
        }
        return false;
    }
};


// euler tour
class Solution {
public:
    int total;
    int n;
    int k;
    string ret;
    unordered_set<string> visited;
    string crackSafe(int n, int k)  {
        this->n = n;
        this->k = k;
        total = pow(k,n);
        string start(n-1,'0');
        dfs(start);
        return start + string(ret.rbegin(), ret.rend());
    }
    
    void dfs(string node) {
        for(int i = 0; i < k; ++i) {
            string path = node + to_string(i);
            if(visited.count(path) == 0) {
                visited.insert(path);
                dfs(path.substr(1));
                ret.push_back('0'+i);
            }
        }
    }
};
