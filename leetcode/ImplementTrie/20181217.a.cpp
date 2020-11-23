// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <string>
#include <cstdlib>

// 56ms 60.66%
class TrieNode {
 public:
  TrieNode* child[26];
  bool term;
  explicit TrieNode(bool b = false) {
    std::memset(child, 0, sizeof(child));
    term = b;
  }
};

class Trie {
  TrieNode* root;
 public:
  /** Initialize your data structure here. */
  Trie() {
    root = new TrieNode();
  }

  /** Inserts a word into the trie. */
  void insert(std::string word) {
    TrieNode* p = root;
    for (int i = 0; i < word.size(); ++i) {
      int n = word[i] - 'a';
      if (p->child[n] == NULL)
        p->child[n] = new TrieNode();
      p = p->child[n];
    }
    p->term = true;
  }

  TrieNode* _search(std::string s) {
    TrieNode* p = root;
    for (int i = 0; i < s.size() && p != NULL; ++i) {
      int n = s[i]-'a';
      p = p->child[n];
    }
    return p;
  }
  /** Returns if the word is in the trie. */
  bool search(std::string word) {
    TrieNode *p = _search(word);
    return p != NULL && p->term;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(std::string prefix) {
    return _search(prefix) != NULL;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
  Trie trie;
  
  trie.insert("apple");
  printf("%s\n", trie.search("apple") ? "true" : "false");   // returns true
  trie.search("app");     // returns false
  printf("%s\n", trie.startsWith("app") ? "true" : "false");   // returns true
  trie.insert("app");
  printf("%s\n", trie.search("app") ? "true" : "false");   // returns true
}
