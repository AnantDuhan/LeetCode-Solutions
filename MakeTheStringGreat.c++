class Solution {
public:
    string makeGood(string s) {
        stack<char>stk;
        string ans;
        for(char i:s) {
            if(!stk.empty() && (i + 32 == stk.top() || i-32 == stk.top())) {
                stk.pop();
            } else {
                stk.push(i);
            }
        }
        while(!stk.empty()) {
            ans = stk.top()+ans;
            stk.pop();
        }
        return ans;
    }
};