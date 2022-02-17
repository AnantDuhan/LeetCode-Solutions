// TC - O(N^2), SC -
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int maxl = 0, maxr = 0;
            for (int j = 0; j <= i; j++) {
                maxl = max(maxl, height[j]);
            }
            for (int j = i; j < n; j++) {
                maxr = max(maxr, height[j]);
            }
            ans += (min(maxl, maxr) - height[i]);
        }
        return ans;
    }
};

// TC - O(N), SC -
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        if (n == 0)
            return 0;
        else {
            int maxl[n + n], maxr[n + n];
            maxl[0] = height[0];
            maxr[n - 1] = height[n - 1];

            for (int l = 1; l < n; l++)
                maxl[l] = max(height[l], maxl[l - 1]);

            for (int r = n - 2; r >= 0; r--)
                maxr[r] = max(height[r], maxr[r + 1]);

            for (int i = 0; i < n; i++)
                ans += (min(maxl[i], maxr[i]) - height[i]);

        }
        return ans;
    }
};


// TC - O(N), SC -
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;

        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] >= lmax)
                    lmax = height[l];
                else
                    ans += (lmax - height[l]);
                l++;
            }
            else
            {
                if (height[r] >= rmax)
                    rmax = height[r];
                else
                    ans += (rmax - height[r]);
                r--;
            }
        }
        return ans;
    }
};