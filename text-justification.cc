class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> line;
        int acc_width = 0;
        int wc = 0;
        vector<string> ret;
        for(auto w : words) {
            int cws = w.size();
            if( acc_width + line.size() + cws > maxWidth) {
                int blanks = maxWidth - acc_width;
                if(line.size() == 1) {
                    string extra(blanks,' ');
                    ret.push_back(line[0] + extra);
                } else {
                    int p = 0;
                    for(int i = 0; i < blanks; ++i) {
                        line[p++ % (line.size() - 1)].push_back(' ');
                    }
                    string tmp = "";
                    for(auto l : line) {
                        tmp += l;
                    }
                    ret.push_back(tmp);
                }
                
                acc_width = 0;
                line.clear();
            } 
            acc_width += cws;
            line.push_back(w);
        }
        
        string tmp = "";
        for(auto l : line) {
            tmp += (l + " ");
        }
        
        if(tmp.size() == maxWidth + 1) {
            tmp.pop_back();
            ret.push_back(tmp);
        } else {
            string extra(maxWidth - tmp.size(), ' ');
            tmp += extra;
            ret.push_back(tmp);
        }
        
        return ret;
    }
};