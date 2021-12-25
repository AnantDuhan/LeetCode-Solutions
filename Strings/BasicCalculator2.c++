class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> stk;
        int n = s.size();
        char sign = '+';
        long long int ans = 0, curr = 0;

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i]))
                curr = curr * 10 + (s[i] - '0');
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (sign == '+')
                    stk.push(curr);
                else if (sign == '-')
                    stk.push(curr * (-1));
                else if (sign == '*') {
                    int num = stk.top();
                    stk.pop();
                    stk.push(num * curr);
                }
                else if (sign == '/') {
                    int num = stk.top();
                    stk.pop();
                    stk.push(num / curr);
                }
                curr = 0;
                sign = s[i];
            }
        }
        while (stk.size()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};