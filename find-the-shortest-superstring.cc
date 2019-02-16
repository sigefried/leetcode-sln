class Solution {
public:
    vector<int> best;
    int best_len;
    vector<vector<int>> graph;
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        graph = vector<vector<int>>(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <n; ++j) {
                if(i == j) continue;
                int overlap = calc(A[i], A[j]);
                graph[i][j] = A[j].size() - overlap;
                //cout << i << " " << j << " " << graph[i][j] << endl;
            }
        }
        
        vector<int> path(n);
        best_len = INT_MAX;
        dfs(A, 0, 0, 0, path);
        string ret = "";
        
        ret = A[best[0]];
        for(int k = 1; k < n; ++k) {
            int i = best[k-1];
            int j = best[k];
            ret += A[j].substr(A[j].size() - graph[i][j]);
        }
        return ret;
    }
    
    void dfs(vector<string>& A, int depth, int visited, int cur_len, vector<int> &path ) {
        if(cur_len > best_len) {
            return;
        }
        if(depth == A.size()) {
            best_len = cur_len;
            best = path;
        }
        for(int i = 0; i < A.size(); ++i) {
            if(visited & (1 << i)) continue;
            path[depth] = i;
            dfs(A, depth + 1, visited | (1 << i), depth == 0 ? A[i].size() : cur_len + graph[path[depth-1]][i], path);
        }
    }
    
    int calc(string x, string y) {
        int len1 = x.size();
        int len2 = y.size();
        int n = min(x.size(), y.size());
        int ret = 0;
        for(int i = 1; i < n; ++i) {
            if (x.compare(len1-i, i, y, 0, i) == 0) {
                ret = i;
            } 
        }
         
        return ret;
    }
};

// greedy not global minimal
class Solution {
public:
    vector<vector<int>> graph;
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        graph = vector<vector<int>>(n, vector<int>(n, 0));
        string ret = "";
        int len = A.size();
        while(len > 1) {
            int l, r;
            int cur_max = 0;
            string tmp, cstr;
            for(int i = 0; i < len; ++i) {
                for(int j = i + 1; j < len; ++j) {
                    int overlap = 0;
                    overlap = calc(A[i],A[j], tmp);
                    if(overlap > cur_max) {
                        cur_max = overlap;
                        cstr = tmp;
                        l = i;
                        r = j;
                    } 
                }
            }
            len--;
            
            if(cur_max == 0) {
                A[0] += A[len];
            } else {
                A[l] = cstr;
                A[r] = A[len];
            }
            
        }

        return A[0];
    }
    
    int calc(string x, string y, string &z) {
        int len1 = x.size();
        int len2 = y.size();
        int n = min(x.size(), y.size());
        int ret = 0;
        for(int i = 1; i < n; ++i) {
            if (x.compare(len1-i, i, y, 0, i) == 0) {
                if(i > ret) {
                    ret = i;
                    z = x + y.substr(i);
                }
                
            } 
        }
        for(int i = 1; i < n; ++i) {
            if (y.compare(len2-i, i, x, 0, i) == 0) {
                if(i > ret) {
                    ret = i;
                    z = y + x.substr(i);
                }
                
            } 
        }
         
        return ret;
    }
};

// tsp DP solution
class Solution {
public:

    vector<vector<int>> graph;
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        graph = vector<vector<int>>(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <n; ++j) {
                if(i == j) continue;
                int overlap = calc(A[i], A[j]);
                graph[i][j] = A[j].size() - overlap;
                //cout << i << " " << j << " " << graph[i][j] << endl;
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        
        for(int i = 0; i < n; ++i) dp[1 << i][i] = A[i].size();
        for(int s = 1; s < (1<<n); ++s) {
            for(int i = 0; i < n; ++i) {
                if(!(s & (1 << i))) continue;
                int prev = s ^ (1 << i);
                for(int j = 0; j < n; ++j) {
                    if(dp[prev][j] + graph[j][i] < dp[s][i]) {
                        dp[s][i] = dp[prev][j] + graph[j][i];
                        parent[s][i] = j;
                    }
                }
            }
        }
        
        auto it = min_element(begin(dp.back()), end(dp.back()));
        int cur  = it - begin(dp.back());
        string ret = "";
        int s  = (1 << n) - 1;
        while(s) {
            int prev = parent[s][cur];
            if(prev < 0) {
                ret = A[cur] + ret;
            } else {
                ret = A[cur].substr(A[cur].size() - graph[prev][cur]) + ret;
            }
            s ^= (1 << cur);
            cur = prev;
        }

        return ret;
    }
    
    int calc(string x, string y) {
        int len1 = x.size();
        int len2 = y.size();
        int n = min(x.size(), y.size());
        int ret = 0;
        for(int i = 1; i < n; ++i) {
            if (x.compare(len1-i, i, y, 0, i) == 0) {
                ret = i;
            } 
        }
         
        return ret;
    }
};