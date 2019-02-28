// sln1
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        long long s1 = 0, s2 = 0;
        int ret = 0;
        for(int i = 0; i < arr.size(); ++i) {
            s1 += sorted[i];
            s2 += arr[i];
            if(s1 == s2) {
                ret++;
            }
        }
        return ret;
    }
};

// sln2

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> lmax(n, 0);
        vector<int> rmin(n, 0);
        lmax[0] = arr[0];
        for(int i = 1; i < n; ++i) {
            lmax[i] = max(lmax[i-1], arr[i]);
        }
        rmin[n-1] = arr[n-1];
        for(int i = n - 2; i >= 0; --i) {
            rmin[i] = min(rmin[i+1], arr[i]);
        }
        
        int ret = 1;
        for(int i = 0; i < n - 1; ++i) {
            if(lmax[i] <= rmin[i+1]) ret++;
        }
        return ret;
    }
};