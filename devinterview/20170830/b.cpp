// Copyright (C) 2017 by iamslash

// Given a dictionary, and two words ‘start’ and ‘target’ (both of
// same length). Find length of the smallest chain from ‘start’ to
// ‘target’ if it exists, such that adjacent words in the chain only
// differ by one character and each word in the chain is a valid word
// i.e., it exists in the dictionary. It may be assumed that the
// ‘target’ word exists in dictionary and length of all dictionary
// words is same.

// Example:

// Input:  Dictionary = {POON, PLEE, SAME, POIE, PLEA, PLIE, POIN}
//             start = TOON
//             target = PLEA
// Output: 7
// Explanation: TOON - POON - POIN - POIE - PLIE - PLEE - PLEA

// g++ b.cpp -std=c++11 -o b.exe

#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <map>

// Exhaustive search
// O(N!)
// ???
int MAX = 987654321;
int BEST = MAX;

void print_indent(int n) {
  n++;
  for (int i = 0; i < n; ++i) {
    printf("  ");
  }
}

bool is_adj(const std::string& a, const std::string& b) {
  if (a.size() != b.size())
    return false;
  int n = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      ++n;
      if (n > 1)
        break;
    }
  }
  if (n == 1)
    return true;
  return false;
}



//////////////////////////////////////////////////////////////////////
// Backtracking
// O(N^2M)
// ???
void _solve(const std::vector<std::string>& v, std::vector<bool>& visited,
            const std::string& prev, const std::string& end, int n_lv) {
  // base condition
  if (is_adj(prev, end)) {
    BEST = std::min(BEST, n_lv);
    return;
  }
  // pruning
  if (BEST <= n_lv)
    return;
  // recursion
  for (int i = 0; i < v.size(); ++i) {
    std::string next = v[i];   
    if (visited[i] == false && is_adj(prev, next)) {
      print_indent(n_lv);
      printf("%s %s\n", prev.c_str(), next.c_str());
      visited[i] = true;
      _solve(v, visited, next, end, n_lv + 1);
      visited[i] = false;
    }
  }
}

int solve(const std::vector<std::string>& v, std::string start, std::string target) {
  std::vector<bool> visited(v.size(), false);
  for (int i = 0; i < v.size(); ++i) {
    std::string next = v[i];
    if (visited[i] == false && is_adj(start, next)) {
      printf("%s %s\n", start.c_str(), next.c_str());
      visited[i] = true;
      _solve(v, visited, next, target, 1);
      visited[i] = false;
    }
  }
  return (BEST == 0 || BEST == MAX) ? 0 : BEST + 2;
}

// //////////////////////////////////////////////////////////////////////
// // BFS
// // O(N^2M)
// // ???
// int _solve(const std::string& start, const std::string& target,
//           std::set<std::string>& s) {
//   std::queue<std::pair<std::string, int> > q;
//   q.push(std::make_pair(start, 1));
//   while (!q.empty()) {
//     std::pair<std::string, int> p = q.front(); q.pop();
//     for (auto it = s.begin(); it != s.end(); ++it) {
//       std::string tmp = *it;
//       if (is_adj(p.first, tmp)) {
//         q.push(std::make_pair(tmp, p.second + 1));
//         s.erase(tmp);
//         if (tmp == target)
//           return p.second;
//       }
//     }
//   }
//   return 0;
// }
// int solve(const std::vector<std::string>& v, std::string start, std::string target) {
//   std::set<std::string> s;
//   for (const auto& e : v)
//     s.insert(e);
//   return _solve(start, target, s);
// }

int main() {
  // int r = solve({"POON", "PLEE", "SAME", "POIE", "PLEA", "PLIE", "POIN"}, "TOON", "PLEA");
  int r = solve({"hot", "dot", "dog", "lot", "log"}, "hit", "cog");
  if (r == 0) {
    printf("IMPOSSIBLE\n");
  } else {
    printf("%d\n", r);
  }
  return 0;
}
