class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int area = 0;

        while (l < r) {
            int lh = height[l];
            int rh = height[r];

            area = max(area, (r - l) * min(lh, rh));

            if (lh < rh)
                l++;
            else
                r--;
        }

        return area;
    }
};