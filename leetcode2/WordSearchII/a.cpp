// Copyright (C) 2018 by iamslash
#include <cstdio>
#include <vector>
#include <string>

static int __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class TrieNode {
 public:  
  TrieNode* next[26];
  std::string word;
};

// 28ms 95.87%
class Solution {
 private:
  std::vector<std::vector<char>> m_B;
  std::vector<std::string> m_rslt;
  int m_h;
  int m_w;
  TrieNode* buildTrie(const std::vector<std::string>& W) {
    TrieNode* t = new TrieNode();
    for (const auto& w : W) {
      TrieNode* p = t;
      for (char c : w) {
        // printf("%10s : %c\n", w.c_str(), c);
        int i = c - 'a';
        if (p->next[i] == NULL)
          p->next[i] = new TrieNode();
        p = p->next[i];
      }
      p->word = w;
    }
    return t;
  }
  void dfs(int y, int x, TrieNode* p, int step) {
    char c = m_B[y][x];
    char i = c - 'a';
    // for (int ii = 0; ii < step; ++ii)
    //   printf(" ");
    // printf("%2d %2d, %c, p->next[i]: %c\n", y, x, c,
    //        p->next[i] ? 'Y' : 'N');
    // base condition
    if (c == '@' || p->next[i] == NULL)
      return;
    // for (int ii = 0; ii < step; ++ii)
    //   printf(" ");
    // printf("m_h-1: %d, m_w-1: %d\n", m_h-1, m_w-1);    

    // check word
    p = p->next[i];
    if (!p->word.empty()) {
      m_rslt.push_back(p->word);
      p->word.clear();
    }

    // recursion
    m_B[y][x] = '@';
    step++;
    if (y > 0) dfs(y-1, x, p, step);
    if (x > 0) dfs(y, x-1, p, step);
    if (y < m_h-1) dfs(y+1, x, p, step);
    if (x < m_w-1) dfs(y, x+1, p, step);
    m_B[y][x] = c;        
  }
 public:
  std::vector<std::string> findWords(
      std::vector<std::vector<char>>& B,
      std::vector<std::string>& W) {
    if (B.empty() || B[0].empty())
      return m_rslt;
    m_B = B;
    m_h = B.size();
    m_w = B[0].size();
    TrieNode* root = buildTrie(W);
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        dfs(y, x, root, 0);
      }
    }
    return m_rslt;
  }
};

int main() {
  std::vector<std::vector<char>> B = {
    {'o', 'a', 'a', 'n'},
    {'e', 't', 'a', 'e'},
    {'i', 'h', 'k', 'r'},
    {'i', 'f', 'l', 'v'}
  };
  std::vector<std::string> W = {
    "oath",
    "pea",
    "eat",
    "rain"
  };

  Solution sln;
  auto rslt = sln.findWords(B, W);
  for (const std::string& s : rslt) {    
    printf("%s\n", s.c_str());
  }

  return 0;
}
