class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return 1;
        int ans = 1;
        int i = 0, j = 1;
        while (j < n) {
            if (arr[j] == arr[j - 1]) {
                i = j; j++;
                continue;
            }
            bool flag = false;
            if (j < n - 1 && ((arr[j] > arr[j - 1] && arr[j + 1] < arr[j]) || (arr[j] < arr[j - 1] && arr[j + 1] > arr[j]))) {
                j++; 
                flag = true;
            }
            ans = max(ans, j - i + 1);
            if (!flag) {
                i = j; 
                j++;
            }
        }
        return ans;
    }
};