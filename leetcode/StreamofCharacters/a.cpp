/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// very confusing problem

// 700ms 48.14% 103.4MB 100.00%
// trie with reversed string
// StreamChecker: O(WS) O(WS)
//         query: O(S) O(S)
class TrieNode {
 public:
  bool term = false;
  TrieNode* next[26];
};
class StreamChecker {
 private:
  TrieNode* root = new TrieNode();
  string sb;
 public:
  StreamChecker(vector<string>& W) {
    build(W);
  }
  bool query(char c) {
    TrieNode* p = root;
    sb += c;
    for (int i = sb.length() - 1; i >= 0 && p; --i) {
      char c = sb[i];
      p = p->next[c-'a'];
      if (p && p->term)
        return true;
    }
    return false;
  }
  void build(vector<string>& W) {
    for (auto& s : W) {
      TrieNode* p = root;
      int n = s.length();
      for (int i = n-1; i >= 0; --i) {
        int idx = s[i]-'a';
        if (!p->next[idx])
          p->next[idx] = new TrieNode();
        p = p->next[idx];
      }
      p->term = true;
    }
  }
};
