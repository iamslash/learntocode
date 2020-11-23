/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>

// 152ms 84.13% 35.4MB 82.93%
// O(AN) O(AN)
// A: length of accounts
// N: length of a account
class DisjointSet {
  std::vector<int> m_parent, m_rank;
 public:
  DisjointSet(int n) : m_parent(n), m_rank(n, 1) {
    for (int i = 0; i < n; ++i)
      m_parent[i] = i;
  }
  int find(int u) {
    if (m_parent[u] == u)
      return u;
    return m_parent[u] = find(m_parent[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (m_rank[v] > m_rank[u])
      std::swap(u, v);
    m_parent[u] = v;
    if (m_rank[u] == m_rank[v])
      ++m_rank[v];
  }
};

class Solution {
 public:
  std::vector<std::vector<std::string>> accountsMerge(
      std::vector<std::vector<std::string>>& A) {
        int n = A.size();
        DisjointSet ds(n);
        std::map<std::string, int> smp_email2id;
        std::vector<std::vector<std::string>> r;

        // set email2id map, ds
        for (int i = 0; i < n; ++i) {
          std::string name = A[i][0];
          for (int j = 1; j < A[i].size(); ++j) {
            std::string email = A[i][j];
            if (smp_email2id.count(email)) {
              int u = smp_email2id[email];
              ds.merge(u, i);
            } else {
              smp_email2id[email] = i;
            }
          }
        }

        // set id2emails map
        std::map<int, std::set<std::string>> smp_id2emails;
        for (auto& pr : smp_email2id) {
          std::string email = pr.first;
          int id = ds.find(pr.second);
          smp_id2emails[id].insert(email);
        }

        // set result
        for (auto& pr : smp_id2emails) {
          std::vector<std::string> line;

          int id = pr.first;
          std::string name = A[id][0];
          line.push_back(name);          
          for (auto& email : pr.second)
            line.push_back(email);
          r.push_back(line);
        }
        
        return r;
  }
};

int main() {

  std::vector<std::vector<std::string>> A =  {
    {"John", "johnsmith@mail.com", "john00@mail.com"},
    {"John", "johnnybravo@mail.com"},
    {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
    {"Mary", "mary@mail.com"}
  };
  Solution sln;
  auto r = sln.accountsMerge(A);
  for (auto& l : r) {
    for (auto& s : l)
      printf("%s ", s.c_str());
    printf("\n");
  }
  
  return 0;
}
