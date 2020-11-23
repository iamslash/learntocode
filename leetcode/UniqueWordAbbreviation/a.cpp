/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

// Q. what is the range of V[i].size()?
// 156ms 90.00% 41.1MB 68.75%
// O(N) O(N)
class ValidWordAbbr {
 private:
  std::unordered_multimap<std::string, std::string> m_ump;
  std::string getAbbr(std::string s) {
    int n = s.size();
    if (n <= 2)
      return s;
    std::string r;
    r += s[0];
    r += std::to_string(n-2);
    r += s[n-1];
    return r;
  }
 public:
  ValidWordAbbr(std::vector<std::string>& V) {
    for (auto& s : V) {
      if (s.empty())
        continue;
      std::string abbr = getAbbr(s);
      // printf("%s\n", abbr.c_str());
      m_ump.insert({abbr, s});
    }
  }
    
  bool isUnique(std::string w) {
    std::string abbr = getAbbr(w);
    auto rng = m_ump.equal_range(abbr);
    if (rng.first == rng.second)
      return true;
    for (auto it = rng.first; it != rng.second; ++it)
      if (it->second != w)
        return false;
    return true;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  std::vector<std::string> V = {"deer", "door", "cake", "card"};
  ValidWordAbbr vwa(V);
  printb(vwa.isUnique("dear"));
  printb(vwa.isUnique("cart"));
  printb(vwa.isUnique("cane"));
  printb(vwa.isUnique("make"));
  return 0;
}
