class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string str = "";
        int i = 0;
        while (i < words.size() and str != s) {
            str += words[i];
            i++;
        }
        return str == s;
    }
};