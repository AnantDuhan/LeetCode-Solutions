// Brute Force
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((time[i] + time[j]) % 60 == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};

// Optimal Solution
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int cnt = 0;
        vector<int> v(60, 0);
        for (int i = 0; i < n; i++) {
            if (time[i] % 60 == 0)
                cnt += v[0];
            else
                cnt += v[60 - (time[i] % 60)];
            v[time[i] % 60]++;
        }
        return cnt;
    }
};