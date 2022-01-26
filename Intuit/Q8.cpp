class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
          int res = 0;
        int n = points.size();
        // iterate over all the points
        for (int i = 0; i < n; ++i) {

            unordered_map<long, int> group(n);

            // iterate over all points other than points[i]
            for (int j = 0; j < n; ++j) {

                if (j == i) continue;

                int dy = points[i].second - points[j].second;
                int dx = points[i].first - points[j].first;

                // compute squared euclidean distance from points[i]
                int edis = dy * dy;
                edis += dx * dx;

                // accumulate # of such "j"s that are "key" distance from "i"
                ++group[edis];
            }

            for (auto& p : group) {
                if (p.second > 1) {
                   
                    res += p.second * (p.second - 1);
                }
            }
        }

    return res;
    }
};