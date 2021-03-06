class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(),0);
        int level = 0, index = 0;
        while(index < seq.size()){
            if(seq[index] =='(')
                res[index] = ++level%2;
            else
                res[index] = level--%2;
            index++;
        }
        return res;
    }
};