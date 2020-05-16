/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/


// Trie node
class TrieNode {
private:
    bool isEnd = false;
    TrieNode* links[26];
public:
    TrieNode() {
        for (auto& i : links)
            i = nullptr;
    }
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }
    TrieNode* get(char ch) {
        return links[ch-'a'];
    }
    void put(char ch, TrieNode* node) {
        links[ch-'a'] = node;
    }
    void setEnd() {
        isEnd = true;
    }
    bool getEnd() {
        return isEnd;
    }
};

// Trie functions
class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (int i=0; i<word.length(); ++i) {
            char curr = word[i];
            if (!node->containsKey(curr)) {
                node->put(curr, new TrieNode());
            }
            node = node->get(curr);
        }
        node->setEnd();
    }

    TrieNode* prefixSearch(string word) {
        TrieNode* node = root;
        for (int i=0; i<word.length(); ++i) {
            char curr = word[i];
            if (!node->containsKey(curr))
                return NULL;
            node = node->get(curr);
        }
        return node;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* res = prefixSearch(word);
        return res != NULL and res->getEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixSearch(prefix) != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
