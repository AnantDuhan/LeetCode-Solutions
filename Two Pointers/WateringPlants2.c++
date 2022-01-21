class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int l = 0;
        int r = n - 1;
        int aliceCap = capacityA;
        int bobCap = capacityB;
        int cnt = 0;
        while (l < r) {
            if (plants[l] > aliceCap) {
                cnt += 1;
                aliceCap = capacityA;
            }
            if (plants[r] > bobCap) {
                cnt += 1;
                bobCap = capacityB;
            }
            aliceCap -= plants[l++];
            bobCap -= plants[r--];
        }
        if (l == r) {
            if (max(aliceCap, bobCap) < plants[l])
                cnt += 1;
        }
    }
};