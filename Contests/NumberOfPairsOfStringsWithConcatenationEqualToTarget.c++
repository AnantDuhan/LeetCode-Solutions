// Brute Force Approach

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                string x = nums[i] + nums[j];
                if (x == target)
                    count++;
            }
        }
        return count;
    }
};

// Optimal Approach

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int m = target.size();
        int count = 0;
        vector<int> prefix(m + 1, 0);
        vector<int> suffix(m + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i].size() >= target.size()) continue;

            int prefIdx = target.compare(0, nums[i].size(), nums[i]) == 0;
            int suffIdx = target.compare(m - nums[i].size(), nums[i].size(), nums[i]) == 0;

            if (prefIdx == true) {
                count += suffix[nums[i].size()];
            }

            if (suffIdx == true) {
                count += prefix[(int)target.length() - (int)nums[i].length() - 1];
            }

            if (prefIdx == true)
                prefix[(int)nums[i].size() - 1]++;
            if (suffIdx == true)
                suffix[(int)m - (int)nums[i].length()]++;
        }
        return count;
    }
};