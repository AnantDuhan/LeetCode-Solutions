class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;
        for (auto word : dictionary) {
            int j = 0, k = 0;
            while (j < s.size() && k < word.size()) {
                if (s[j] == word[k])
                    k++;
                j++;
            }

            int n = word.size();
            if (k == n && ((ans.size() == n && ans > word) || ans.size() < n))
                ans = word;
        }
        return ans;
    }
};