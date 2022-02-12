class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;

        bool isPresent = false;

        for (auto word : wordList) {
            if (endWord.compare(word) == 0)
                isPresent = true;
            wordSet.insert(word);
        }

        if (isPresent == false)
            return 0;

        // for BFS declaring a queue
        queue<string> q;
        q.push(beginWord);

        int dep = 0;
        while (q.empty() == false) {
            dep = dep + 1;
            int size = q.size();
            while (size--) {
                string curr = q.front();
                q.pop();

                for (int i = 0; i < curr.length(); i++) {
                    string tmp = curr;
                    for (char c = 'a'; c <= 'z'; c++) {
                        tmp[i] = c;
                        if (curr.compare(tmp) == 0)
                            continue;
                        if (tmp.compare(endWord) == 0)
                            return dep + 1;

                        if (wordSet.find(tmp) != wordSet.end()) {
                            q.push(tmp);
                            wordSet.erase(tmp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};