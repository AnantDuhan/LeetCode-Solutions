// 1st Approach
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        for(auto i=0;i<n;i++) {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')') {
                if(!st.empty())
                    st.pop();
                else
                    s[i] = '*';
            }
        }
        
        while(!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};

// 2nd Approach
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int n = s.size();
        for(int i=0;i<n;i++) {
            if(s[i] == '(')
                open++;
            else if(s[i] == ')')
                open--;
            if(open < 0)
                s[i] = '*', open++;
        }
        int close = 0;
        for(int i=n-1;i>=0;i--) {
            if(s[i] == '(')
                close--;
            else if(s[i] == ')')
                close++;
            if(close < 0)
                s[i] = '*', close++;
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
