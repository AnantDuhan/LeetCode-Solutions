class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        string res;
        unordered_set<string_view> st;
        int low = 1, high = n;   
        while(low<=high) {
            int mid = (low + high)/2;
            bool found = false;
            for(int i = 0;i+mid <= n;i++) {
                auto[it, inserted] = st.emplace(s.data()+i, mid);
                if(!inserted) {
                    found = true;
                    res = move(*it);
                    break;
                }
            }
            if(found)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return res;
    }
};
