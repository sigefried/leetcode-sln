class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        double ret = INT_MAX;
        map<string, vector<pair<int,int>>> mp;
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                long dis = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                double centerX = (double)(points[j][0] + points[i][0])/2;
                double centerY = (double)(points[j][1] + points[i][1])/2;
                string key = to_string(dis) + "+" + to_string(centerX) + "+" + to_string(centerY);
                mp[key].push_back({i,j});
            }
        }
        for(auto it : mp) {
            if(it.second.size() > 1) {
                auto cands = it.second;
                for(int i = 0; i < cands.size() - 1; ++i) {
                    for(int j = i + 1; j < cands.size(); ++j) {
                        int p1 = cands[i].first; 
                        int p2 = cands[j].first;
                        int p3 = cands[j].second; 
                        double len1 = sqrt((points[p1][0] - points[p2][0]) * (points[p1][0] - points[p2][0]) +  (points[p1][1] - points[p2][1]) * (points[p1][1] - points[p2][1]));
                        double len2 = sqrt((points[p1][0] - points[p3][0]) * (points[p1][0] - points[p3][0]) +  (points[p1][1] - points[p3][1]) * (points[p1][1] - points[p3][1]));
                        double area = len1 * len2; 
                        ret = min(area, ret);
                    }
                }
            }
        }
        
        return ret == INT_MAX ? 0 : ret;
    }
};