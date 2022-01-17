class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (target > 1 && --maxDoubles >= 0) {
            int inc = target % 2;
            ans += 1 + inc;
            target /= 2;
        }
        return ans + target - 1;
    }
};

// New Approach
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        int steps = 0;
        while (target > 1 && maxDoubles != 0) {
            if (target % 2 == 0) {
                target /= 2;
                maxDoubles -= 1;
            } else {
                target -= 1;
            }
            cnt++;
        }
        cnt += (target - 1);
        return cnt;
    }
};