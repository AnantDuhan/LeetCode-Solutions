class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c/2);i++) {
            double a = sqrt((double)(c-i*i));
            if(floor(a) == ceil(a)) {
                return true;
            }
        }
        return false;
    }
};