class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), (k - 1) / 2);
        vector<double> ret;
        for(int i = k; ;++i) {
            ret.push_back((static_cast<double>(*mid) + *next(mid, (k+1) % 2)) / 2.0);
            
            if(i == nums.size()) return ret;
            
            window.insert(nums[i]);
            if (nums[i] < *mid) mid = prev(mid); 
            if (nums[i - k] <= *mid) mid = next(mid);
            window.erase(window.lower_bound(nums[i - k])); 
        }
    }
};

//---------------------- another solution
//class Solution {
public:


    vector<int> nums;
    set<pair<long long,long long>> left;
    set<pair<long long,long long>> right;


    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        int n = nums.size();
        for(int i = 0; i < k; ++i) {
            left.insert({nums[i], i});
        }
        rebalance();
        //cout << left.size() << "," << right.size() << endl;
        ans.push_back(getMedian(k));
        for(int i = k, r = 1; i < n; i++, r++) {
            // remove out date one
            pair<long long,long long> old = {nums[i - k], i - k};
            pair<long long,long long> cur = {nums[i], i};
            if(left.count(old) > 0) {
                left.erase(old);
            } else {
                right.erase(old);
            }

            // add to right, then down to left
            right.insert(cur);
            left.insert(*right.begin());
            right.erase(right.begin());


            //run rebalance
            rebalance();
            ans.push_back(getMedian(k));

        }

        return ans;
    }

    double getMedian(int k) {
        if(k % 2 != 0) {
            return right.begin()->first;
        } else {
            return (left.rbegin()->first + right.begin()->first) / 2.0;
        }
    }

    void rebalance() {
        while(left.size() > right.size()) {
            right.insert(*left.rbegin());
            auto end = left.end();
            left.erase(--end);
        }
    }
};
