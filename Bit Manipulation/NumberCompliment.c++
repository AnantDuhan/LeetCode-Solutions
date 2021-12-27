class Solution {
public:
    int findComplement(int num) {
        vector<int> v;

        while (num != 0) {
            v.push_back(num % 2);
            num = num / 2;
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
            num = num + v[i] * two;
            two = two * 2;
        }
        return num;
    }
};