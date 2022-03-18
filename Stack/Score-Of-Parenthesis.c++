// Stack Approach
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ind = 0;
        
        for(char c: s) {
            if(c == '(') {
                st.push(ind);
                ind = 0;
            } else {
                ind = st.top() + max(2*ind, 1);
                st.pop();
            }
        }
        return ind;
    }
};

// 2nd Approach
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, bal = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(')
                bal++;
            else {
                bal--;
                if(s[i-1] == '(')
                    ans += 1 << bal;
            }
        }
        return ans;
    }
};
