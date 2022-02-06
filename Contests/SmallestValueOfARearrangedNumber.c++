class Solution {
public:
    long long smallestNumber(long long num) {
        long long freq[10] = {0};
        bool pos = (num > 0);
        num = abs(num);
        while (num) {
            long long d = num % 10;
            freq[d]++;
            num = num / 10;
        }
        long long res = 0;
        if (pos) {
            for (int i = 1; i <= 9; i++) {
                if (freq[i]) {
                    res = i;
                    freq[i]--;
                    break;
                }
            }
            for (int i = 0 ; i <= 9 ; i++)
                while (freq[i]--)
                    res = res * 10 + i;
        } else {
            for (int i = 9; i >= 1; i--) {
                if (freq[i]) {
                    res = i;
                    freq[i]--;
                    break;
                }
            }
            for (int i = 9 ; i >= 0 ; i--)
                while (freq[i]--)
                    res = res * 10 + i;
            res = -res;
        }
        return res;
    }
};