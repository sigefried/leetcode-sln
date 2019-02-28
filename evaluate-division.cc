// dfs
class Solution {
public:
     map<string, map<string, double>> graph;
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
       
        vector<double> ret;
        int n = equations.size();
        for(int i = 0; i < n; ++i) {
            string u = equations[i].first;
            string v = equations[i].second;
            graph[u][v] = values[i];
            graph[v][u] = 1.0 / values[i];
        }
        
        for(auto q : queries) {
            set<string> visited;
            ret.push_back(dfs(q.first, q.second,visited));
        }
        return ret;
    }
    
    double dfs(string start, string end, set<string> &visited) {
        if(graph.count(start) == 0) {
            return -1;
        }
        
        if(graph[start].count(end) > 0) {
            return graph[start][end];
        }
        visited.insert(start);
        for(auto e : graph[start]) {
            if(visited.count(e.first) == 0) {
                double subValue = dfs(e.first, end, visited);
                if(subValue != -1) {
                    return e.second * subValue;
                }
            }
        }
        return -1;
    }
};


// uf

class DS {
public:
    DS() {};
    map<string, string> parent;
    map<string, double> value;
    void init(string k) {
        if(parent.count(k) == 0) {
            parent[k] = k;
            value[k] = 1.0;
        }
    }
    string find_parent(string x) {
        if(parent[x] != x) {
            auto px = parent[x];
            auto ppx = find_parent(parent[x]);
            parent[x] = ppx;
            value[x] = value[x] * value[px];
        }
        return parent[x];
    }
  
    void merge(string x, string y, double ratio) {
        string px = find_parent(x);
        string py = find_parent(y);
        if(px != py) {
            parent[py] = px;
            value[py] = ratio * ( value[x] / value[y] );
        }
    }
    void print_ds() {
        for(auto it : parent) {
            find_parent(it.first);
            cout << it.first << " : " << value[it.first] << endl;
        }
    }
};    

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ret(queries.size(), -1);
        int n = equations.size();
        DS ds;
        for(int i = 0; i < n; ++i) {
            ds.init(equations[i].first);
            ds.init(equations[i].second);
            ds.merge(equations[i].second, equations[i].first, values[i]);
        }
        
        for(int i = 0; i < queries.size(); ++i) {
            if(ds.parent.count(queries[i].first) &&
               ds.parent.count(queries[i].second) &&
               ds.find_parent(queries[i].first) == ds.find_parent(queries[i].second)) {
                ret[i] = ds.value[queries[i].first] / ds.value[queries[i].second];
            }
        }
        return ret;
    }
};