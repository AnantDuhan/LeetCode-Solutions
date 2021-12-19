class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']')
                st.push(s[i]);
            else {
                string currStr = "";

                while (st.top() != '[') {
                    currStr = st.top() + currStr;
                    st.pop();
                }

                st.pop();
                string num = "";

                while (!st.empty() and isdigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }

                int convert = stoi(num);

                while (convert--) {
                    for (int j = 0; j < currStr.size(); j++)
                        st.push(currStr[j]);
                }
            }
        }
        s = "";
        while (!st.empty()) {
            s = st.top() + s;
            st.pop();
        }

        return s;
    }
};