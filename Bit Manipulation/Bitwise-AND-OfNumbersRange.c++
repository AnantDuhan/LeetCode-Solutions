class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while (left != right) {
            count++;
            left /= 2;
            right /= 2;
        }
        return left << count;
    }
};