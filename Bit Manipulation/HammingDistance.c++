class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int bits = 0;
        while (n > 0) {
            bits += n & 1;
            n >>= 1;
        }
        return bits;
    }
};