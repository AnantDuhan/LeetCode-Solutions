class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int size = flowerbed.length;
        int i = 0, cnt = 0;
        while (i < size) {
            if (flowerbed[i] == 0 && (i == size - 1 || flowerbed[i + 1] == 0) && (i == 0 || flowerbed[i - 1] == 0)) {
                flowerbed[i] = 1;
                cnt++;
            }
            i++;
        }
        return cnt >= n;
    }
};