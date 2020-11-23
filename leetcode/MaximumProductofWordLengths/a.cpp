// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <string>
#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<std::string>& W) {
    std::vector<int> B;  // bits for words
    int n = W.size();
    int rslt = 0;

    for (int i = 0; i < n; ++i) {
      int w = 0;
      for (char c : W[i]) {
        w |= (1 << (c - 'a'));
      }
      B.push_back(w);
      for (int j = 0; j < i; ++j) {
        if (((B[j] & B[i]) == 0) &&
            (W[j].size() * W[i].size() > rslt)) {
          rslt = W[j].size() * W[i].size();
        }
      }
    }

    return rslt;
  }
};

int main() {

  std::vector<std::string> W0 = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
  std::vector<std::string> W1 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
  std::vector<std::string> W2 = {"a", "aa", "aaa", "aaaa"};
  
  Solution sln;
  printf("%d\n", sln.maxProduct(W0));
  printf("%d\n", sln.maxProduct(W1));
  printf("%d\n", sln.maxProduct(W2));
  return 0;
}
