class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double l = 0, r = 10e6;
        while ((r-l) > 10e-6) {
            double m = (r + l) / 2.0;
            if(possible(m, stations, K )) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    }
    bool possible(double D, vector<int>& stations, int K) {
        int used = 0;
        for (int i = 0; i < stations.size() - 1; ++i)
            used += (int) ((stations[i+1] - stations[i]) / D);
        return used <= K;
    }
};