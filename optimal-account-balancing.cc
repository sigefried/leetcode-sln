class Solution {
public:
    vector<long> debt;
    int minTransfers(vector<vector<int>>& transactions) {
        map<int, int> balmap;
        for(auto trans : transactions) {
            int sender = trans[0];
            int receiver = trans[1];
            int amount = trans[2];
            balmap[sender] -= amount;
            balmap[receiver] += amount;
        }
        for(auto it : balmap) {
            if(it.second != 0) {
                debt.push_back(it.second);
            }
        }
        
        return dfs(0);
    }
    
    //min transaction
    long dfs(int i) {
        while(i < debt.size() && debt[i] == 0) i++;
        //cout << i << endl;
        //cout << debt.size() << endl;
        if(i == debt.size()) return 0;
        long ret = INT_MAX;
        int prev = 0;
        for(int j = i + 1; j < debt.size(); ++j) {
            if(debt[i] * debt[j] < 0 && debt[j] != prev ) {
                debt[j] += debt[i];
                ret = min(ret, 1 + dfs(i+1));
                debt[j] -= debt[i];
                prev = debt[j];
            }
        }
        return ret;
    }
};