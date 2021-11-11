class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int part = 0, count = 0;
        if (sum % 3 == 0) {
            for (int x : arr) {
                part += x;
                if (part == (sum / 3)) {
                    count++;
                    part = 0;
                }
            }
        }
        return count >= 3;
    }
};