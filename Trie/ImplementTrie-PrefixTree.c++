class Trie {
    Trie* child[26];
    bool isEnd;
public:
    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }

    void insert(string word) {
        Trie* curr = this;
        for (char c : word) {
            if (!(curr->child[c - 'a']))
                curr->child[c - 'a'] = new Trie();
            curr = curr->child[c - 'a'];

        }
        curr->isEnd = true;
    }

    bool search(string word) {
        Trie* curr = this;
        for (char c : word) {
            curr = curr->child[c - 'a'];
            if (!curr)
                return false;
        }
        if (curr->isEnd)
            return true;
        return false;
    }

    bool startsWith(string prefix) {
        Trie* curr = this;
        for (char c : prefix) {
            curr = curr->child[c - 'a'];
            if (!curr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */