/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>

// 52ms 70.12%
class TrieNode {
 public:
  TrieNode* m_next[26];
  bool m_term;
  TrieNode() {
    for (int i = 0; i < 26; ++i)
      m_next[i] = NULL;
    m_term = false;
  }
};

class Trie {
 private:
  TrieNode* m_root;
 public:
  /** Initialize your data structure here. */
  Trie() {
    m_root = new TrieNode();
  }
    
  /** Inserts a word into the trie. */
  void insert(std::string s) {
    TrieNode* p = m_root;
    for (int i = 0; i < s.size(); ++i) {
      int j = s[i] - 'a';
      if (p->m_next[j] == NULL)
        p->m_next[j] = new TrieNode();
      p = p->m_next[j];        
    }
    p->m_term = true;
  }
    
  /** Returns if the word is in the trie. */
  bool search(std::string s) {
    TrieNode* p = m_root;
    for (int i = 0; i < s.size(); ++i) {
      int j = s[i] - 'a';
      if (p->m_next[j] == NULL)
        return false;
      p = p->m_next[j];
    }
    return p->m_term == true;
  }
    
  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(std::string s) {
    TrieNode* p = m_root;
    for (int i = 0; i < s.size(); ++i) {
      int j = s[i] - 'a';
      if (p->m_next[j] == NULL)
        return false;
      p = p->m_next[j];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  Trie tr;
  tr.insert("apple");
  printb(tr.search("apple"));
  printb(tr.search("app"));
  printb(tr.startsWith("app"));
  tr.insert("app");
  printb(tr.search("app"));
  
  return 0;
}
