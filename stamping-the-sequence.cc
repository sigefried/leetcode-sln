class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        string str = target;
        string aim(target.length(),'*');
        while(str != aim) {
            int tmp = remove(str, stamp);
            if(tmp == str.size()) return {};
            ans.push_back(tmp);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int remove(string &str, string stamp) {
        for(int i = 0; i < str.size(); ++i) {
            int j = 0, tmp = i;
            bool flag = false;
            while(j < stamp.size() && tmp < str.size() && (str[tmp] == '*' || str[tmp] == stamp[j])) {
                if(str[tmp] == stamp[j]) {
                    flag = true;
                }
                tmp++;
                j++;
            }
            if(j == stamp.size() && flag) {
                for(int k = 0; k < stamp.size(); ++k) {
                    str[i+k] = '*';
                }
                return i;
            }
        }
        return str.size();
    }
};