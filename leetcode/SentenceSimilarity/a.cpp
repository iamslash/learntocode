/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>

// 12ms 99.68% 11MB 93.55%
// O(N) O(N)
class Solution {
 public:
  bool areSentencesSimilar(
      std::vector<std::string>& A, std::vector<std::string>& B,
      std::vector<std::pair<std::string, std::string>> P) {
    if (A.size() != B.size())
      return false;
    int n = A.size();
    std::map<std::string, std::set<std::string>> smp;
    for (auto pr : P)
      smp[pr.first].insert(pr.second);
    for (int i = 0; i < n; ++i) {
      if (A[i] != B[i] && smp[A[i]].count(B[i]) == 0 &&
          smp[B[i]].count(A[i]) == 0)
        return false;
    }
    return true;
  }
};

int main() {

  // std::vector<std::string> A = {"great","acting","skills"};
  // std::vector<std::string> B = {"fine","drama","talent"};
  // std::vector<std::pair<std::string, std::string>> P =
  //     {{"great","fine"},{"drama","acting"},{"skills","talent"}};

  std::vector<std::string> A = {"an","extraordinary","meal"};
  std::vector<std::string> B = {"one","good","dinner"};
  std::vector<std::pair<std::string, std::string>> P =
      {{"great","good"},
       {"extraordinary","good"},
       {"well","good"},
       {"wonderful","good"},
       {"excellent","good"},
       {"fine","good"},
       {"nice","good"},
       {"any","one"},
       {"some","one"},
       {"unique","one"},
       {"the","one"},
       {"an","one"},
       {"single","one"},
       {"a","one"},
       {"truck","car"},
       {"wagon","car"},
       {"automobile","car"},
       {"auto","car"},
       {"vehicle","car"},
       {"entertain","have"},
       {"drink","have"},
       {"eat","have"},
       {"take","have"},
       {"fruits","meal"},
       {"brunch","meal"},
       {"breakfast","meal"},
       {"food","meal"},
       {"dinner","meal"},
       {"super","meal"},
       {"lunch","meal"},
       {"possess","own"},
       {"keep","own"},
       {"have","own"},{"extremely","very"},{"actually","very"},
       {"really","very"},
       {"super","very"}};

  Solution sln;
  printf("%s\n", sln.areSentencesSimilar(A, B, P) ? "true" : "false");
  
  return 0;
}
