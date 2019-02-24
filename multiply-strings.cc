class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> tmp(m + n, 0);
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0' );
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = mul + tmp[p2];
                tmp[p2] = sum % 10;
                tmp[p1] += sum / 10;
            }
        }
        
        string ret;
        for(auto n : tmp) {
            if(!(ret.size() == 0 && n == 0)) ret.push_back(n + '0');
        }
        
        return ret.size() == 0 ? "0" : ret;
    }
};