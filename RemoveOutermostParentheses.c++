class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;        
        string output;
        
        for (auto &c : s) {
            if (c == '(') {
                if (!st.empty()) {
                    output += '(';
                }
                st.emplace(c);
            } else if (c == ')') {
                st.pop();
                if (!st.empty()) {
                    output += ")";
                }                
            }
        }
        
        return output;
    }
};