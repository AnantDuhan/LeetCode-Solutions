class Solution {
public:
    bool enough(int x, int m, int n, int k) {
        int cnt = 0;
        for(int i=1;i<=m;i++) {
            cnt += min(x/i, n);
        }
        return cnt >= k;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m*n;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(!enough(mid,m,n,k))
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};