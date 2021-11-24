// Brute Force

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i, j, n = nums.size();
        int leftsum, rightsum;

        for (i = 0; i < n; ++i)
        {
            leftsum = 0;
            for (j = 0; j < i; j++)
                leftsum += nums[j];

            rightsum = 0;
            for (j = i + 1; j < n; j++)
                rightsum += nums[j];

            if (leftsum == rightsum)
                return i;
        }
        return -1;
    }
};

// Optimal Approach

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, Lsum = 0;
        int n = nums.size();
        for (int x : nums)
            sum += x;
        for (int i = 0; i < n; ++i) {
            if (Lsum == sum - Lsum - nums[i])
                return i;
            Lsum += nums[i];
        }
        return -1;
    }
};
