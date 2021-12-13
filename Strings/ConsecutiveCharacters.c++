class Solution {
public:
    int maxPower(string s) {
        int currMax = 0, maxLen = 0;
        int n = s.size();
        if (n == 1)
            return 1;

        for (int i = 1; i <= n; i++) {
            if (s[i] == s[i - 1])
                currMax++;
            else
                currMax = 0;

            maxLen = max(maxLen, currMax + 1);
        }
        return maxLen;
    }
};