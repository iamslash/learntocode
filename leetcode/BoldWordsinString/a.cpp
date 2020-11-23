
#include <cstdio>
#include <vector>
#include <string>
#include <set>

// painting strategy
// O(WS) O(S)
class Solution {
 public:
  std::string boldWords(std::vector<std::string>& W, std::string s) {
    // make bolds
    std::vector<bool> bolds(s.size());
    for (auto& w : W) {
      int pos = s.find(w);
      while (pos != std::string::npos) {
        for (int i = 0; i < w.size(); ++i)
          bolds[pos+i] = true;
        pos = s.find(w, pos+1);
      }
    }
    
    // make rslt;
    std::string rslt;
    for (int i = 0; i < bolds.size(); ++i) {
      if (bolds[i]) {
        rslt += "<b>";
        while (i < bolds.size() && bolds[i])
          rslt += s[i++];
        rslt += "</b>";
      }
      if (i < bolds.size())
        rslt += s[i];
    }
    return rslt;
  }
};

int main() {
  std::vector<std::string> W = {"ab", "bc"};
  std::string s = "aabcd";
  // std::vector<std::string> W = {"ccb","b","d","cba","dc"};
  // std::string s = "eeaadadadc"; // "eeaa<b>d</b>a<b>d</b>a<b>dc</b>"
  // std::vector<std::string> W = {"b","dee","a","ee","c"};
  // std::string s = "cebcecceab"; // "<b>c</b>e<b>bc</b>e<b>cc</b>e<b>ab</b>"

  Solution sln;
  printf("%s\n", sln.boldWords(W, s).c_str());
  
  return 0;
}
