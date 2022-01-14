class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        stringstream geek(s);
        int x = 0;
        geek >> x;
        return x;
    }
};