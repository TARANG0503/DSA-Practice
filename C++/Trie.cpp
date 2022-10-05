class node {
public:
    bool leaf;
    node* children[26];
    node() {
        leaf = false;
        for (int i = 0; i < 26; ++i)
            children[i] = NULL;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    node* root;
    Trie() {
        root = new node();
    }

    /** Inserts a word into the trie. */
    void insert(string str) {
        auto it = str.begin();
        auto t = root;
        while (it != str.end()) {
            if (t -> children[*it - 'a'] == NULL)
                t -> children[*it - 'a'] = new node;
            t = t -> children[*it - 'a'];
            ++it;
        }
        t -> leaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string str) {
        auto it = str.begin();
        auto t = root;
        while (it != str.end()) {
            if (t -> children[*it - 'a'] == NULL)
                return false;
            t = t -> children[*it - 'a'];
            ++it;
        }
        return t -> leaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string str) {
        auto it = str.begin();
        auto t = root;
        while (it != str.end()) {
            if (t -> children[*it - 'a'] == NULL)
                return false;
            t = t -> children[*it - 'a'];
            ++it;
        }
        return true;
    }
};
