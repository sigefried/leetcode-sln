class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string begin=to_string(board[0][0])+to_string(board[0][1])+to_string(board[0][2])
             +to_string(board[1][0])+to_string(board[1][1])+to_string(board[1][2]);
        
        vector<vector<int>> nextMoves{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        unordered_set<string> visited{begin};
        queue<string> q; q.push(begin);
        for(int depth = 0; !q.empty(); ++depth) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                auto cur = q.front(); q.pop();
                int zero_idx = cur.find("0");
                if(cur == target) return depth;
                for(auto nxt_idx : nextMoves[zero_idx]) {
                    auto cand = cur;
                    swap(cand[zero_idx], cand[nxt_idx]);
                    if(visited.find(cand) == visited.end()) {
                        visited.insert(cand);
                        q.push(cand);
                    }
                }
            }
        }
        
        
        return -1;
    }
};