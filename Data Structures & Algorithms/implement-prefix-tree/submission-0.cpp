class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';   // assuming lowercase letters
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';

        if (root->children[index] == NULL)
            return false;

        return searchUtil(root->children[index], word.substr(1));
    }

    bool startsWithUtil(TrieNode* root, string prefix) {
        if (prefix.length() == 0)
            return true;

        int index = prefix[0] - 'a';

        if (root->children[index] == NULL)
            return false;

        return startsWithUtil(root->children[index], prefix.substr(1));
    }

public:
    PrefixTree() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};