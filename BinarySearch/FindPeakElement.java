// Brute Force
// TC - O(N), SC - O(1)
class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return n - 1;
    }
}

// Binary Search - Iterative
// TC - O(logn), SC - O(1)
class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int low = 0, high = n - 1;
        if (low == high)
            return low;
        while (low < high) {
            int mid = (high + low) / 2;
            if (nums[mid] > nums[mid + 1])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
}