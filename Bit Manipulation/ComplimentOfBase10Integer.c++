class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int> v;

        if (n == 0)
            return 1;

        while (n != 0) {
            v.push_back(n % 2);
            n = n / 2;
        }
        reverse(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0)
                v[i] = 1;
            else
                v[i] = 0;
        }
        long long int two = 1;
        for (int i = v.size() - 1; i >= 0; i--) {
            n = n + v[i] * two;
            two = two * 2;
        }
        return n;
    }
};