class TopVotedCandidate {
public:
    map<int, int> m;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        unordered_map<int, int> pcount;
        int leader = persons[0];
        pcount[persons[0]]++;
        m[times[0]] = persons[0];
        int n = persons.size();
        for(int i  = 1; i < n; ++i) {
            pcount[persons[i]]++;
            if(pcount[persons[i]] >= pcount[leader]) {
                leader = persons[i];
            }
            m[times[i]] = leader;
        }
        
    }

    int q(int t) {
        return (--m.upper_bound(t))-> second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */