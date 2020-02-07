struct dist_pair {
    int dist;
    int worker;
    int bike;
    bool operator <(const dist_pair &other) const {
        if(dist != other.dist) {
            return dist > other.dist;
        } else if (worker != other.worker) {
            return worker > other.worker;
        } else {
            return bike > other.bike;
        }
    }
};

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        priority_queue<dist_pair> pq;
        
        for(int i  = 0; i < workers.size(); ++i) {
            for(int j = 0; j < bikes.size(); ++j) {
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                pq.push({d,i,j});  
            }
        }
        
        vector<int> assign(workers.size(), -1);
        vector<bool> visitedBike(bikes.size(), false);
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if(assign[cur.worker] == -1 && visitedBike[cur.bike] == false) {
                assign[cur.worker] = cur.bike;
                visitedBike[cur.bike] = true;
            }
        }
        
        return assign;  
    }
};