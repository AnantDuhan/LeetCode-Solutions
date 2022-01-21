TC - O(N + 2K)
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int N = 2 * 100000 + 1;
        vector<int> prefix(N);
        for (auto &it : fruits) {
            prefix[it[0]] = it[1];
        }
        for (int i = 1; i < N; i++) {
            prefix[i] += prefix[i - 1];
        }
        int maxi = 0;
        // move to the right
        for (int i = startPos; i <= min(startPos + k, N - 1); i++) {
            int r = i;
            int x = i - startPos;
            int l = startPos - (k - 2 * x);
            l = min(l, startPos);

            int sum = prefix[r];
            if (l > 0) {
                sum -= prefix[l - 1];
            }
            maxi = max(maxi, sum);
        }

        // move to the left
        for (int i = startPos; i >= max(0, startPos - k); i--) {
            int l = i;
            int x = startPos - i;
            int r = startPos + (k - 2 * x);
            r = max(min(r, N - 1), startPos);
            int sum = prefix[r];
            if (l > 0) {
                sum -= prefix[l - 1];
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

// Optimal Approach
class Solution {
private:
    bool isValid(int startPos, int k , int left, int right) {
        if (right <= startPos) {
            return startPos - left <= k;
        } else if (left >= startPos) {
            return right - startPos <= k;
        } else {
            int x = startPos - left;
            int y = right - startPos;
            if (left <= right && 2 * x + y <= k || 2 * y + x <= k)
                return true;
            else
                return false;
        }
    }

public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int maxi = 0;
        int left = 0;
        int right = 0;
        int sum = 0;
        int n = fruits.size();
        while (right < n) {
            sum += fruits[right][1];
            while (left <= right && isValid(startPos, k, fruits[left][0], fruits[right][0]) == false) {
                sum -= fruits[left][1];
                left++;
            }
            maxi = max(maxi, sum);
            right++;
        }
        return maxi;
    }
};