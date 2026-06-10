#include <iostream>
#include <unordered_map>
#include <string>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(const std::string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }

    bool search(const std::string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children.count(c)) return false;
            cur = cur->children[c];
        }
        return cur->isEnd;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->children.count(c)) return false;
            cur = cur->children[c];
        }
        return true;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    t.insert("app");
    t.insert("apply");

    std::cout << t.search("app")      << "\n"; // 1
    std::cout << t.search("ap")       << "\n"; // 0
    std::cout << t.startsWith("appl") << "\n"; // 1
    std::cout << t.search("apply")    << "\n"; // 1
    return 0;
}
