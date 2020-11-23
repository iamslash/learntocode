/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <cstring>
#include <string>

class TrieNode {
 public:
  bool term;
  TrieNode* children[26];
  TrieNode() : term(false) {
    for (int i = 0; i < 26; ++i)
      children[i] = NULL;
  }
};

class WordDictionary {
 private:
  TrieNode* root;
 public:
  /** Initialize your data structure here. */
  WordDictionary() {
    root = new TrieNode();
  }
    
  /** Adds a word into the data structure. */
  void addWord(std::string word) {
    TrieNode* u = root;
    for (int i = 0; i < word.size(); ++i) {
      int j = word[i] - 'a';
      if (u->children[j] == NULL)
        u->children[j] = new TrieNode();
      u = u->children[j];
    }
    u->term = true;
  }
    
  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(std::string word) {
    return _search(word.c_str(), root);
  }

  bool _search(const char* sz, TrieNode* t) {
    TrieNode* u = t;
    for (int i = 0; sz[i]; ++i) {
      int j = sz[i] - 'a';
      if (u && sz[i] != '.') {
        u = u->children[j];
      } else if (u && sz[i] == '.') {
        TrieNode* tmp = u;
        for (int k = 0; k < 26; ++k) {
          u = tmp->children[k];
          if (_search(sz+i+1, u))
            return true;
        }
      } else {
        break;
      }
    }
    return u && u->term;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  WordDictionary w;
  w.addWord("bad");
  w.addWord("dad");
  w.addWord("mad");
  printb(w.search("pad"));
  printb(w.search("bad"));
  printb(w.search(".ad"));
  printb(w.search("b.."));
  return 0;
}
