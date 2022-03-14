class Solution {
public:
    string simplifyPath(string path) {
        
        string res;
        stack<string> st;
        
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == '/')
                continue;
            
            string tmp;
            
            while(i < path.size() && path[i] != '/') {
                // add path to tmp string
                tmp += path[i];
                i++;
            }
            if(tmp == ".")
                continue;
            // pop the top element from stack if it exists
            else if(tmp == "..") {
                if(!st.empty())
                    st.pop();
            } else
                st.push(tmp);
        }
        
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};
