/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

class Solution {
 public:
  std::string optimalDivision(std::vector<int>& V) {
    std::string rslt;

    if (V.empty())
      return rslt;

    rslt = std::to_string(V[0]);

    if (V.size() == 1)
      return rslt;

    if (V.size() == 2)
      return rslt + "/" + std::to_string(V[1]);

    rslt += "/(";

    for (int i = 1; i < V.size(); ++i)
      rslt += std::to_string(V[i]) + "/";

    rslt.pop_back();
    rslt += ")";
    
    return rslt;
    
  }
};

int main() {
  std::vector<int> V = {1000, 100, 10, 2};
  
  Solution sln;
  printf("%s\n", sln.optimalDivision(V).c_str());
  
  return 0;
}
