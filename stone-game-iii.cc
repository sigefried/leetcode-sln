class Solution {
public:
    unordered_map<int, int> memo;
    string stoneGameIII(vector<int>& stoneValue) {
        int ans = dfs(stoneValue, 0);
        if (ans == 0) {
            return "Tie";
        } else if(ans > 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
    
    
    int dfs(vector<int> &stones, int i) {
        if(i >= stones.size()) {
            return 0;
        }
        if(memo.count(i) > 0) return memo[i];
        int sum = stones[i];
        // minus next optimal
        int value = sum - dfs(stones, i + 1);
        for(int j = i + 1; j < min(i+3, (int)stones.size()); ++j) {
            sum += stones[j];
            value = max(value, sum - dfs(stones, j + 1));
        }
        memo[i] = value;
        return value;
    }
};