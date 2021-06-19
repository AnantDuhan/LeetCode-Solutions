class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int tmp(0), ans(0), num;
        char op = '+';
        int size = s.size();
        for(char ch: s)
        {
            size--;
            if(isdigit(ch))
            {
                tmp = tmp * 10 + (ch - '0');
            }
            if(!isdigit(ch) and !isspace(ch) || !size)
            {
                switch(op)
                {
                    case '+':
                        st.push(tmp);
                        break;
                    case '-':
                        st.push(-tmp);
                        break;
                    case '*':
                        num = st.top();
                        st.pop();
                        st.push(num * tmp);
                        break;
                    default:
                        num = st.top();
                        st.pop();
                        st.push(num / tmp);
                        
                }
                tmp = 0;
                op = ch;
            }
        }
        
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans; 
    }
};