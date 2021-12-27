// Brute Force - O(M+N)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0, c = 0;
        vector<int> v(m + n);

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                v[c] = nums1[i];
                c++;
                i++;
            } else {
                v[c] = nums2[j];
                c++;
                j++;
            }
        }

        while (i < m) {
            v[c] = nums1[i];
            i++;
            c++;
        }

        while (j < m) {
            v[c] = nums2[j];
            j++;
            c++;
        }

        if ((m + n) == 1) {
            return v[0];
        }
        if ((m + n) % 2 == 1) {
            return v[(m + n) / 2] * 1.0;
        } else {
            int mid1 = (m + n) / 2;
            int mid2 = mid1 - 1;
            return ((v[mid1] + v[mid2]) / 2.0);
        }
    }
};

// Optimal Approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }
};