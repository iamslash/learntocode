/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// 9ms 100.00% 9.7MB 87.23%
class TrieNode {
 public:
  bool bterm = false;
  int val = 0;
  TrieNode* next[26] = {NULL,};
};

class MapSum {
 private:
  TrieNode* root;
 public:
  MapSum() {
    root = new TrieNode();
  }
    
  void insert(std::string key, int val) {
    TrieNode* p = root;
    for (char c : key) {
      int i = c - 'a';
      if (p->next[i] == NULL)
        p->next[i] = new TrieNode();
      p = p->next[i];
      // printf("%s %c %d\n", key.c_str(), i + 'a', p->val);
    }
    p->bterm = true;
    p->val = val;
  }

  int _sum(TrieNode* u) {
    // recursion
    int r = u->bterm ? u->val : 0;
    for (int i = 0; i < 26; ++i) {
      if (u->next[i])
        r += _sum(u->next[i]);
    }
    return r;
  }
    
  int sum(std::string prf) {
    TrieNode* p = root;
    for (int i = 0; i < prf.size(); ++i) {
      int pos = prf[i] - 'a';
      if (p->next[pos] == NULL)
        return 0;
      p = p->next[pos];      
    }
    return _sum(p);
  }
};

int main() {
  MapSum mp;
  // mp.insert("apple", 3);
  // printf("%d\n", mp.sum("ap"));
  // mp.insert("app", 2);
  // printf("%d\n", mp.sum("ap"));
  // printf("%d\n", mp.sum("k"));

  mp.insert("aa", 3);
  printf("%d\n", mp.sum("a"));
  mp.insert("aa", 2);
  printf("%d\n", mp.sum("a"));

  return 0;
}
