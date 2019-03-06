class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ret(s.size() + 1,0);
        for(int i = 0; i < ret.size(); ++i) {
            ret[i] = i + 1;
        }
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'D') {
                int j = i;
                while(j < s.size() && s[j] == 'D') j++;
                reverse(ret, i, j);
                
                i = j;
            }
        }
        return ret;
    }
    
    void reverse(vector<int> &ret, int i, int j) {
        //cout << i << " " << j << endl;
        while(i < j) {
            swap(ret[i++], ret[j--]);
        }
    }
};