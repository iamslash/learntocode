/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// 464ms 48.95% 185.8MB 8.35%
// BFS
class Solution {
 private:
  // hot: (dot, lot)
  std::vector<std::string> getNextWords(
      std::string w,
      std::unordered_set<std::string>& D) {
    std::vector<std::string> rslt;
    for (int i = 0; i < w.size(); ++i) {
      char b = w[i];
      for (char c = 'a'; c <= 'z'; ++c) {
        w[i] = c;
        if (D.count(w))
          rslt.push_back(w);
      }
      w[i] = b;
    }
    return rslt;
  }
 public:
  std::vector<std::vector<std::string>> findLadders(
      std::string bw, std::string ew,
      std::vector<std::string>& W) {
    std::vector<std::vector<std::string>> rslt;
    std::unordered_set<std::string> seen;
    std::queue<std::vector<std::string>> q;
    std::unordered_set<std::string> pool(W.begin(), W.end());
    q.push({bw});
    // found shortest path?
    bool bflag = false;
    // BFS loop
    while (q.size()) {
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        auto u = q.front(); q.pop();
        auto nextwords = getNextWords(u.back(), pool);
        for (auto& nw : nextwords) {
          std::vector<std::string> v = u;
          v.push_back(nw);
          if (nw == ew) {
            bflag = true;
            rslt.push_back(v);
          }
          seen.insert(nw);
          q.push(v);
        }
      }
      // end condition
      if (bflag)
        break;
      for (auto it = seen.begin(); it != seen.end(); ++it)
        pool.erase(*it);
      seen.clear();
    }
    return rslt;
  }
};

int main() {
  // std::string B = "hit";
  // std::string E = "cog";
  // std::vector<std::string> W = {
  //   "hot","dot","dog","lot","log","cog"
  // };
  // std::vector<std::string> W = {
  //   "hot","dot","dog","lot","log"
  // };


  std::string B = "qa";
  std::string E = "sq";
  std::vector<std::string> W = {
    "si","go","se","cm","so",
    "ph","mt","db","mb","sb","kr",
    "ln","tm","le","av","sm","ar",
    "ci","ca","br","ti","ba","to",
    "ra","fa","yo","ow","sn","ya",
    "cr","po","fe","ho","ma","re",
    "or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr",
    "pa","he","lr","sq","ye"};
  Solution sln;
  auto rslt = sln.findLadders(B, E, W);
  for (auto& l : rslt) {
    for (auto& s : l)
      printf("%s ", s.c_str());
    printf("\n");
  }
  
  return 0;
}
