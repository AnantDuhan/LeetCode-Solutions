// Brute Force
// TC - O(N^2), TC - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = n / 2;
        for (int num : nums) {
            int cnt = 0;
            for (int elem : nums) {
                if (elem == num)
                    cnt++;
            }
            if (cnt > majority)
                return num;
        }
        return -1;
    }
};

// Hashmap
// TC - O(N), SC - O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), ans;
        unordered_map<int, int> um;

        for (int i = 0; i < n; i++) {
            um[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (um[nums[i]] > n / 2) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};


// Sorting
// TC - O(NlogN), SC - O(1) or O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// Boyer-Moore Voting Algo
// TC - O(N), SC - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), maj = nums[0], cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == maj)
                cnt++;
            else
                cnt--;

            if (cnt == 0) {
                maj = nums[i];
                cnt = 1;
            }
        }
        return maj;
    }
};