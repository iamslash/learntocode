/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>

// 344ms 74.01% 163.6MB 33.56%
//  ctor: O(K*L)
// input: O(MlgM)
struct TrieNode {
  char m_c;
  std::unordered_map<char, TrieNode*> m_next;
  std::unordered_map<std::string, int> m_cnts;
  TrieNode(char c) : m_c(c){}  
};
struct Compare {
  bool operator() (const std::pair<std::string, int>& a,
                   const std::pair<std::string, int>& b) const {
    return a.second == b.second ?
        a.first > b.first :
        a.second < b.second;
  }
};
class AutocompleteSystem {
 private:
  TrieNode* m_proot;
  std::string m_prefix;
  void insert(std::string s, int t) {
    TrieNode* u = m_proot;
    for (char c : s) {
      if (!u->m_next[c])
        u->m_next[c] = new TrieNode(c);
      u = u->m_next[c];
      u->m_cnts[s] += t;
    }
  }
 public:
  AutocompleteSystem(std::vector<std::string> S, std::vector<int> T) {
    m_proot = new TrieNode(' ');
    m_prefix = "";
    for (int i = 0; i < S.size(); ++i)
      insert(S[i], T[i]);
  }
  std::vector<std::string> input(char c) {
    if (c == '#') {
      insert(m_prefix, 1);
      m_prefix = "";
      return {};
    }
    m_prefix += c;
    TrieNode* u = m_proot;
    for (char d : m_prefix) {
      if (!u->m_next[d])
        return {};
      u = u->m_next[d];
    }
    // pick up 3 candidates
    std::priority_queue<
      std::pair<std::string, int>,
      std::vector<std::pair<std::string, int>>,
      Compare> pq;
    for (auto& pr : u->m_cnts)
      pq.push(pr);
    std::vector<std::string> rslt;
    for (int i = 0; i < 3 && pq.size(); ++i) {
      rslt.push_back(pq.top().first);
      pq.pop();
    }
    return rslt;
  }  
};

void printv(std::vector<std::string> V) {
  for (auto& s : V)
    printf("%s\n", s.c_str());
  printf("-----\n");
}

int main() {

  std::vector<std::string> S = {
    "i love you", "island","ironman", "i love leetcode"
  };
  std::vector<int> T = {5, 3, 2, 2};
  
  AutocompleteSystem as(S, T);
  printv(as.input('i'));
  printv(as.input(' '));
  printv(as.input('a'));
  printv(as.input('#'));
  printv(as.input('i'));
  printv(as.input(' '));
  printv(as.input('a'));
  printv(as.input('#'));
  printv(as.input('i'));
  printv(as.input(' '));
  printv(as.input('a'));
  printv(as.input('#'));
  
  
  // std::set<std::pair<int, std::string>> sst;
  // sst.insert({-3, "hello"});
  // sst.insert({-10, "world"});
  // sst.insert({-1, "This"});

  // for (auto pr : sst) {
  //   printf("%d %s\n", -pr.first, pr.second.c_str());
  // }
  
  return 0;
}
