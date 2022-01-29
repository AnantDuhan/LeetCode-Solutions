class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size(), area = 0;
        stack<int> ind;
        for (int i = 0; i < n; i++) {
            while (!ind.empty() && heights[ind.top()] > heights[i]) {
                int h = heights[ind.top()];
                ind.pop();
                int l = ind.empty() ? -1 : ind.top();
                area = max(area, h * (i - l - 1));
            }
            ind.push(i);
        }
        return area;
    }
};