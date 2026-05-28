class Trie {
public:
    Trie() = default;

    void insert(string word) {
        // current node in trie
        Trie* node = this;

        // iterate through the word string
        for (int i = 0; i < static_cast<int>(word.length()); i++) {
            int const idx = word[i] - 'a';

            // if next node is empty
            if (node->children[idx] == nullptr) {
                // create a new node
                node->children[idx] = new Trie();
            }

            // advance to next node
            node = node->children[idx];
        }

        // we've finished inserting the nodes
        node->isEnd = true;
    }

    bool search(string word) {
        // current node in trie
        Trie* node = this;

        // iterate through the word string
        for (int i = 0; i < static_cast<int>(word.length()); i++) {
            int const idx = word[i] - 'a';

            // if next node is empty
            if (node->children[idx] == nullptr) {
                return false;
            }

            // advance to next node
            node = node->children[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        // current node in trie
        Trie* node = this;

        // iterate through the word string
        for (int i = 0; i < static_cast<int>(prefix.length()); i++) {
            int const idx = prefix[i] - 'a';

            // if next node is empty
            if (node->children[idx] == nullptr) {
                return false;
            }

            // advance to next node
            node = node->children[idx];
        }

        return true;
    }

    Trie* children[26] = {nullptr};
    bool isEnd = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */