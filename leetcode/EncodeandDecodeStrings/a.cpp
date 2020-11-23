/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 68ms 75.38% 28.7MB 61.11%
// O(N) O(N)
class Codec {
 public:
  std::string encode(std::vector<std::string>& V) {
    std::string rslt;
    for (auto& s : V)
      rslt += std::to_string(s.size()) + ":" + s;
    return rslt;
  }
  std::vector<std::string> decode(std::string s) {
    std::vector<std::string> rslt;
    int i = 0, j = 0;
    while ((j = (int)s.find_first_of(":", i)) != std::string::npos) {
      int n = std::stoi(s.substr(i, j-i));
      std::string a = s.substr(j+1, n);
      rslt.push_back(a);
      i = j + 1 + n;
    }
    return rslt;
  }
};

int main() {
  std::vector<std::string> V ={
    "Hello",
    "World"
  };

  Codec cdc;
  std::string s = cdc.encode(V);
  printf("%s\n", s.c_str());
  auto r = cdc.decode(s);
  for (auto& a : r)
    printf("%s\n", a.c_str());  
  return 0;
}
