class Solution {
public:
    void backtrack(vector<string>& result, unordered_map<char, vector<char>> map, string digits, string cur, int i)
    {
        if (cur.length() == digits.length()) {
            result.push_back(cur);
            return;
        }
        
        for (char ch : map[digits[i]]) {
            backtrack(result, map, digits, cur + ch, i + 1);
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        if (digits.length() == 0) {
            return {};
        }
        
        unordered_map<char, vector<char>> map = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        
        vector<string> result;
        backtrack(result, map, digits, "", 0);
        return result;
    }
};