// Brute Force
// TC - O(mn), SC - O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 1;
        while (true) {
            int time = 0;
            for (int pile : piles) {
                time += pile / speed + (pile % speed != 0);
                if (time > h)
                    break;
            }
            if (time <= h) {
                return speed;
            } else {
                speed += 1;
            }
        }
    }
};

// Binary Search
// TC - O(nlogm), SC - O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = (high + low) / 2;
            int time = 0;
            for (int pile : piles) {
                time += pile / mid + (pile % mid != 0);
            }
            if (time <= h)
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
};