class Vector2D {
public:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
    Vector2D(vector<vector<int>>& vec2d) {
        for (auto &vec : vec2d) {
            q.push({vec.begin(), vec.end()});
        }
    }

    int next() {
        if (hasNext()) {
            auto &it = q.front();
            int ret = *(it.first);
            it.first++;
            return ret;
        }
        return -1;
    }

    bool hasNext() {
        if (q.empty()) return false;
        while (!q.empty()) {
            auto it = q.front();
            if (it.first != it.second) return true;
            else {
                q.pop();
            }
        }
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */


 //-----------------------------------------------

 class Vector2D {
public:
    vector<vector<int>>::iterator i, iEnd;
    int j;
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iEnd = vec2d.end();
        j = 0;
    }

    int next() {
        hasNext();
        return (*i)[j++];
    }

    bool hasNext() {
        while (i != iEnd && j == (*i).size()) {
            i++;
            j = 0;
        }
        return i != iEnd;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */