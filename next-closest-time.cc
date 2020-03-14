class Solution {
public:
    
    int mins[4] = {600, 60 , 10, 1};
    
    string nextClosestTime(string time) {
        size_t colon = time.find(':');
        int cur = stoi(time.substr(0, colon)) * 60 + stoi(time.substr(colon + 1));
        string next = "0000";
        int d;
        for(int i = 1; i <= 1440; ++i) {
            
            int m = (cur + i) % 1440;
            for (d = 0; d < 4; d++) {
                next[d] = '0' + m / mins[d]; m %= mins[d];
                if (time.find(next[d]) == string::npos) break;
            }
            
            if(d == 4) break;
        }
        return next.substr(0, 2) + ':' + next.substr(2, 2);
    }
};