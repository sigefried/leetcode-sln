class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int sz = matrix.size();
    if (sz == 0) return;
    for (int layer = 0; layer < sz / 2; ++layer) {
      for (int p = layer; p < sz-layer-1; ++p) {
        int tmp = matrix[layer][p];
        matrix[layer][p] = matrix[sz-1-p][layer];
        matrix[sz-1-p][layer] = matrix[sz-1-layer][sz-1-p];
        matrix[sz-1-layer][sz-1-p] = matrix[p][sz-1-layer];
        matrix[p][sz-1-layer] = tmp;
      }
    }
  }
};
