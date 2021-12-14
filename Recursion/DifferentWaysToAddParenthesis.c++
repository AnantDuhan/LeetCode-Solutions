// Brute Force
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                int x = left.size();
                int y = right.size();
                for (int j = 0; j < x; j++) {
                    for (int k = 0; k < y; k++) {
                        if (expression[i] == '+') {
                            res.push_back(left[j] + right[k]);
                        }
                        else if (expression[i] == '-') {
                            res.push_back(left[j] - right[k]);
                        }
                        else {
                            res.push_back(left[j] - right[k]);
                        }
                    }
                }
            }

            if (res.empty())
                res.push_back(stoi(expression));
        }
        return res;
    }
};

// Optimal Approach
class Solution {
public:
    unordered_map<string, vector<int>> ump;

    vector<int> recursion(string s) {
        int n = s.length();
        if (n <= 2) {
            vector<int> v(1, stoi(s));
            return v;
        }

        if (ump.find(s) != ump.end())
            return ump[s];

        vector<int> res;
        for (int i = 1; i < n; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                string left = s.substr(0, i);
                string right = s.substr(i + 1, n - i);
                vector<int> lv = recursion(left);
                vector<int> rv = recursion(right);
                for (auto l : lv) {
                    for (auto r : rv) {
                        if (s[i] == '+') res.push_back(l + r);
                        else if (s[i] == '-') res.push_back(l - r);
                        else if (s[i] == '*') res.push_back(l * r);
                        else res.push_back(l / r);
                    }
                }
            }
        }
        return ump[s] = res;
    }

    vector<int> diffWaysToCompute(string expression) {
        return recursion(expression);
    }
};