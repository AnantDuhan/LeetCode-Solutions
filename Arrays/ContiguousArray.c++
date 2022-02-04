// TC - O(N^2), SC -
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cntOnce = 0, cntZeroes = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == 0)
                    cntZeroes++;
                else
                    cntOnce++;
                if (cntZeroes == cntOnce)
                    maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};

// TC - O(N), SC - O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int preSum = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                nums[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            preSum += nums[i];
            if (preSum == 0)
                res = i + 1;
            if (m.find(preSum) == m.end())
                m[preSum] = i;
            else
                res = max(res, i - m[preSum]);
        }
        return res;
    }
};