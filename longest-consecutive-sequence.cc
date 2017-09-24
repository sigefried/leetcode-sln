class UnionFind {
    public:
    unordered_map<int,int> parent;
    unordered_map<int,int> ssize;
    int max_size;
    
    void init(vector<int> &nums) {
        for (auto n : nums) {
            parent[n] = n;
            ssize[n] = 1;
           
        }
        max_size = nums.size() > 0 ? 1 : 0;
    }
    
    void _union(int target, int other) {
        if (parent.count(other) == 0) return;
        int pa = find_parent(target);
        int pb = find_parent(other);
        if (pa == pb) return;
        parent[pb] = pa;
        ssize[pa] += ssize[pb];
        max_size = max(max_size, ssize[pa]);
    }
    
    int find_parent(int target) {
        if (parent[target] != target) {
            parent[target] = find_parent(parent[target]);
        }
        return parent[target];
    }
    
    int maxSize() {
        return max_size;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        UnionFind uf;
        uf.init(nums);
        for (auto n : nums) {
            uf._union(n,n-1);
            uf._union(n,n+1);
        }
        return uf.maxSize();
    }
};
