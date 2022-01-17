class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res((s.size() + k - 1) / k, string(k, fill));
        for (int i = 0; i < s.size(); i++)
            res[i / k][i % k] = s[i];
        return res;
    }
};

// New Approach
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            res += s[i];
            if (res.size() == k) {
                ans.push_back(res);
                res = "";
            }
        }
        if (res.size() > 0 && res.size() != k) {
            while (res.size() != k) {
                res += fill;
            }
            ans.push_back(res);
        }
        return ans;
    }
};