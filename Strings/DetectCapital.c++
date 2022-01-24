// Brute Force
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();

        bool match1 = true, match2 = true, match3 = true;

        // case1
        for (int i = 0; i < n; i++) {
            if (!isupper(word[i])) {
                match1 = false;
                break;
            }
        }

        if (match1)
            return true;

        //case2
        for (int i = 0; i < n; i++) {
            if (!islower(word[i])) {
                match2 = false;
                break;
            }
        }

        if (match2)
            return true;

        //case3
        if (!isupper(word[0]))
            match3 = false;

        if (match3) {
            for (int i = 1; i < n; i++) {
                if (!islower(word[i])) {
                    match3 = false;
                    break;
                }
            }
        }
        if (match3)
            return true;

        return false;
    }
};

// shortened above code
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();

        if (n == 1)
            return true;

        if (isupper(word[0]) && isupper(word[1])) {
            for (int i = 2; i < n; i++) {
                if (islower(word[i]))
                    return false;
            }
        } else {
            for (int i = 1; i < n; i++) {
                if (isupper(word[i]))
                    return false;
            }
        }
        return true;
    }
};