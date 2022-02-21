// HashMap
// TC - O(N), SC - O(N)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> um;

        for (int i = 0; i < n; i++) {
            um[nums[i]]++;
        }

        for (auto i : um) {
            if (i.second > n / 3) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};

// Boyer Moore's Voting Algo
// TC - O(N), SC - O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        int num1 = INT_MIN;
        int num2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == num1)
                cnt1++;
            else if (nums[i] == num2)
                cnt2++;
            else if (cnt1 == 0) {
                num1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0) {
                num2 = nums[i];
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == num1)
                cnt1++;
            else if (nums[i] == num2)
                cnt2++;
        }

        if (cnt1 > n / 3)
            ans.push_back(num1);
        if (cnt2 > n / 3)
            ans.push_back(num2);
        return ans;
    }
};