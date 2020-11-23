/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

// 300ms 64.38% 49.6MB 98.68%
// DisjointSet
// O(1) O(N)
class Solution {
 private:
  // {child : parent}
  std::unordered_map<std::string, std::string> m_ds;
  std::string find(std::string u) {
    if (m_ds.count(u) && m_ds[u] == u)
      return u;
    return m_ds[u] = find(m_ds[u]);
  }
  void merge(std::string u, std::string v) {
    if (!m_ds.count(u))
      m_ds[u] = u;
    if (!m_ds.count(v))
      m_ds[v] = v;
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    m_ds[v] = u;
  }
 public:
  bool areSentencesSimilarTwo(
      std::vector<std::string>& W1,
      std::vector<std::string>& W2,
      std::vector<std::vector<std::string>>& D) {

    if (W1.size() != W2.size())
      return false;

    for (auto& s : W1)
      m_ds[s] = s;
    for (auto& s : W2)
      m_ds[s] = s;
    for (auto& v : D) {
      merge(v[0], v[1]);
    }

    for (auto& pr : m_ds) {
      printf("%s : %s\n", pr.first.c_str(), pr.second.c_str());
    }

    for (int i = 0; i < W1.size(); ++i) {
      std::string u = find(W1[i]);
      std::string v = find(W2[i]);
      if (u != v)
        return false;
    }   
    
    return true;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  std::vector<std::string> W1 = {
    "great", "acting", "skills"
  };
  std::vector<std::string> W2 = {
    {"fine", "drama", "talent"}    
  };
  std::vector<std::vector<std::string>> D = {
    {"great", "good"},
    {"fine", "good"},
    {"acting","drama"},
    {"skills","talent"}    
  };
  Solution sln;
  printb(sln.areSentencesSimilarTwo(W1, W2, D));
  
  return 0;
}
