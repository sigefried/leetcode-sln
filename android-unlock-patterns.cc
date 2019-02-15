class Solution {
public:
    
    map<int, map<int,int>> skip;
    vector<bool> visited;
    int dfs(int cur, int remain) {
        if(remain < 0) return 0;
        if(remain == 0) return 1;
        visited[cur] = true;
        int ret = 0;
        for(int i = 1; i <= 9; ++i) {
            if(visited[i]) continue;
            int mid = skip[cur][i];
            if(mid == 0 || visited[mid]) {  //no skip point or already visited
                ret += dfs(i, remain-1);
            }
        }
        
        visited[cur] = false;
        return ret;
    }
    int numberOfPatterns(int m, int n) {
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        int ret = 0;
        visited = vector<bool>(10, false);
        for(int i = m; i <=n; ++i) {
            ret += dfs(1, i - 1) * 4;
            ret += dfs(2, i - 1) * 4;
            ret += dfs(5, i - 1);
        }
        return ret;
    }
};