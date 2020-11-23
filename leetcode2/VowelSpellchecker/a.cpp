/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

// 96ms 57.33% 29.5MB 60.35%
// hashmap
// O(max(W,Q)) O(W)
class Solution {
 private:
  std::string tolow(std::string &s) {
    std::string r = s;
    for (char &c : r)
      c = std::tolower(c);
    return r;
  }
  std::string tonrm(std::string &s) {
    std::string r = tolow(s);
    for (char &c : r) {
      if (c == 'a' || c == 'e' || c == 'i' ||
          c == 'o' || c == 'u')
        c = '#';
    }
    return r;
  }
 public:
  std::vector<std::string> spellchecker(
      std::vector<std::string>& W,
      std::vector<std::string>& Q) {
    std::set<std::string> wrdsst(W.begin(), W.end());
    std::unordered_map<std::string, std::string> low2wrd, nrm2wrd;
    for (auto& w : W) {
      std::string low = tolow(w);
      std::string nrm = tonrm(w);
      low2wrd.insert({low, w});
      nrm2wrd.insert({nrm, w});
    }
    for (auto &s : Q) {
      // dot not need to fix
      if (wrdsst.count(s))
        continue;
      std::string low = tolow(s);
      std::string nrm = tonrm(s);
      if (low2wrd.count(low)) {
        s = low2wrd[low];
      } else if (nrm2wrd.count(nrm)) {
        s = nrm2wrd[nrm];
      } else {
        s = "";
      }
    }
    return Q;
  }
};

int main() {
  return 0;
}
