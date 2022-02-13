class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long n = beans.size(), ans = LLONG_MAX, sum = accumulate(beans.begin(), beans.end(), 0L);
        sort(beans.begin(), beans.end());
        for (long long i = 0; i < n; i++) {
            ans = min(ans, sum - (n - i) * beans[i]);
        }
        return ans;
    }
};