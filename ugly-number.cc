class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false;
        vector<int> div = {2,3,5};
        for(auto d : div) {
            while(num % d == 0) {
                num /= d;
            }
        }
        return num == 1;
    }
};