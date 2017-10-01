class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

//----------------------------------------------------------------


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return r_find(nums,0,nums.size()-1, nums.size() -k + 1);
    }
    int r_find(vector<int> &nums, int start, int end, int k) {
        int mid = partition(nums,start,end);
        int count = mid - start + 1;
        if (count == k) {
            return nums[mid];
        } else if (count > k) {
            return r_find(nums,start,mid-1,k);
        } else {
            return r_find(nums,mid+1,end,k-count);
        }
    }
    
    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[start];
        int bar = start;
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[++bar]);
            }
        }
        swap(nums[start], nums[bar]);
        return bar;
    }
};