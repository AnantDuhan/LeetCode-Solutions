class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int mod = 1e9 + 7, n = nextVisit.size();
        vector<long> psum(n);
        for (int i = 0; i < n - 1; i++) {
            long t = 2 + (psum[i] + mod - psum[nextVisit[i]]) % mod;
            psum[i + 1] = (t + psum[i]) % mod;
        }
        return psum.back();
    }
};