/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 72ms 86.89% 48.5MB 100.00%
// O(N) O(D)
class TrieNode {
 private:
  bool m_bterm = false;
  TrieNode* m_next[26] = {0,};
 public:
  // w: word, fr : from, sz : zero idx of word
  void insert(std::string& w, int fr, int sz) {
    m_bterm |= fr == sz;
    // base
    if (m_bterm)
      return;
    // recursion
    int i = w[fr]-'a';
    if (m_next[i] == NULL)
      m_next[i] = new TrieNode();
    m_next[i]->insert(w, fr+1, sz);    
  }
  // s: sentence, st: idx of sentence,
  // fr: from idx of word, sz: zero idx of sentence
  int root(std::string& s, int st, int fr, int sz) {
    // base
    if (st + fr == sz || s[st + fr] == ' ' || m_bterm)
      return fr;
    int i = s[st+fr]-'a';
    if (m_next[i] == NULL) {
      while (st+fr<sz && s[st+fr] != ' ')
        ++fr;
      return fr;
    }
    // recursion
    return m_next[i]->root(s, st, fr+1, sz);                              
  }
};

class Solution {
 public:
  std::string replaceWords(std::vector<std::string>& D,
                      std::string s) {
    TrieNode tn;
    std::string rslt;
    int i = 0;
    for (auto& a : D)
      tn.insert(a, 0, a.size());
    while (i < s.size()) {
      if (s[i] == ' ')
        rslt += s[i++];
      int cnt = tn.root(s, i, 0, s.size());
      rslt += s.substr(i, cnt);
      while (i < s.size() && s[i] != ' ')
        ++i;
    }

    return rslt;
  }
};

int main() {
  std::vector<std::string> D = {"cat", "bat", "rat"};
  std::string s = "the cattle was rattled by the battery";

  Solution sln;
  printf("%s\n", sln.replaceWords(D, s).c_str());
  
  return 0;
}
