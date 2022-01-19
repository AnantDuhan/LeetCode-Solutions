// TC - (len of array * size of string)
class Solution {
private:
    bool check(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &it : words) {
            if (check(it))
                return it;
        }
        return "";
    }
};