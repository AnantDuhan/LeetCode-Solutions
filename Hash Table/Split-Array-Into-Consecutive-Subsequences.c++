class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, end;

        for (int i : nums)
            cnt[i]++;

        for (int i : nums) {
            if (cnt[i] == 0)
                continue;
            cnt[i]--;
            if (end[i - 1] > 0) {
                end[i - 1]--;
                end[i]++;
            } else if (cnt[i + 1] > 0 && cnt[i + 2] > 0) {
                cnt[i + 1]--;
                cnt[i + 2]--;
                end[i + 2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};