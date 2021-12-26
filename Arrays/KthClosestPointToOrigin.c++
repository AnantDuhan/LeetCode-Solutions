// Brute Force
class Solution {
private:
    int sqDistance(vector<int>& points) {
        return points[0] * points[0] + points[1] * points[1];
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
            return sqDistance(a) < sqDistance(b);
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};