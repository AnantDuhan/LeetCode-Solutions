// TC - O(N^2)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int mini = nums[i];
            int maxi = nums[i];
            for (int j = i; j < n; j++) {
                mini = min(nums[j], mini);
                maxi = max(maxi, nums[j]);

                sum += (maxi - mini);
            }
        }
        return sum;
    }
};

// NGE - Next Greater Element, NSE - Next Smallest Element
class Solution {
private:
    long long sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
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
            }
            st.push(i);
        }
        return sum;
    }

private:
    long long sumSubarrayMaxs(vector<int>& arr) {
        long long sum = 0;
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i <= n; i++) {
            // remove all elements that are greater than arr[i]
            // in stack i want to maintain the increasing order

            while (!st.empty() && (i == n || arr[st.top()] < arr[i])) {
                int  j = st.top();
                st.pop();

                long long right = i - j;

                int prevTop = -1;
                if (st.empty() == false)
                    prevTop = st.top();

                long long left = j - prevTop;

                sum += (long long)(arr[j] * left * right);
            }
            st.push(i);
        }
        return sum;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};