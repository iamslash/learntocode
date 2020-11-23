/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 4ms 100.00% 9.5MB 56.82%
// search: O(N) O(N)
class TrieNode {
 public:
  bool bterm = false;
  TrieNode* next[26] = {NULL,};
  void insert(std::string& s, int u) {
    // base
    if (u == s.size()) {
      bterm = true;
      // printf("%s %d\n", s.c_str(), u);      
      return;
    }

    // recursion
    int i = s[u] - 'a';
    if (next[i] == NULL)
      next[i] = new TrieNode();
    // printf("%s %d %c\n", s.c_str(), u, s[u]);
    next[i]->insert(s, u + 1);
  }
  bool find(std::string& s, int u) {
    // printf("%s s[%d]: %c %c\n", s.c_str(), u, s[u], bterm ? 't' : 'f');
    // base
    if (u == s.size()) {
      if (bterm)
        return true;
      return false;
    }

    // recursion
    int i = s[u] - 'a';
    if (next[i])
      return next[i]->find(s, u+1);
    return false;
  }  
};

class MagicDictionary {
 private:
  TrieNode* root;
 public:
  MagicDictionary() {
    root = new TrieNode();
  }
    
  void buildDict(std::vector<std::string> dict) {
    for (std::string& s : dict) {
      root->insert(s, 0);
    }
  }
    
  bool search(std::string s) {
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < 26; ++j) {
        char c = j + 'a';
        if (c == s[i])
          continue;
        char o = s[i];
        s[i] = c;
        if (root->find(s, 0))
          return true;
        s[i] = o;
      }
    }
    return false;
    // return root->find(s, 0);
  }
};

void printb(bool b) {
  printf("%s\n", b ? "True" : "False");
}

int main() {
  MagicDictionary md;
  md.buildDict({"hello", "leetcode"});
  printb(md.search("hello"));
  printb(md.search("hhllo"));
  printb(md.search("hell"));
  printb(md.search("leetcoded"));
  return 0;
}
