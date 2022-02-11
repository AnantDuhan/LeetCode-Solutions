class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n)
            return false;
        vector<int> cnt1(26, 0), cnt2(26, 0);

        int i;
        for (i = 0; i < m; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        if (cnt1 == cnt2)
            return true;

        int start = 0, end = i;
        while (end < n) {
            cnt2[s2[start] - 'a']--;
            cnt2[s2[end] - 'a']++;

            if (cnt1 == cnt2)
                return true;
            end++;
            start++;
        }
        return false;
    }
};