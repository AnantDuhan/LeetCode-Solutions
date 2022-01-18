class Solution {
private:
    bool check(long long mid, vector<int> &batteries, int n) {
        long long total = mid * n;
        long long cnt = 0;
        for (auto &it : batteries) {
            cnt += min((long long)it, mid);
        }
        return cnt >= total;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (auto &it : batteries)
            sum += it;
        long long low = 0, high = sum;
        long long ans = 0;
        while (low <= high) {
            long long mid = (high + low) / 2;
            if (check(mid, batteries, n)) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};