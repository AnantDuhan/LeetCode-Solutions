// Brute Force - O(N^2) - TLE
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int mini = arr[i];
            for (int j = i; j < n; j++) {
                mini = min(arr[j], mini);
                sum += mini;
            }
        }
        int mod = 1e9 + 7;
        return sum % mod;
    }
};

// Monotonic Stack
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        long long mod = 1e9 + 7;
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i <= n; i++) {
            // remove all elements that are greater than arr[i]
            // in stack i want to maintain the increasing order

            while (!st.empty() && (i == n || arr[st.top()] > arr[i])) {
                int  j = st.top();
                st.pop();

                long long right = i - j;

                int prevTop = -1;
                if (st.empty() == false)
                    prevTop = st.top();

                long long left = j - prevTop;

                sum += (long long)(arr[j] * left * right);
                sum %= mod;
            }
            st.push(i);
        }
        return sum % mod;
    }
};