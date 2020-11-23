/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <numeric>
#include <vector>

// s1: ab
//        i
//     j
// s2: eidbaooo

// Q: size of s1 is less than size of s2 ???
//    character is multibyte ???
// O(N) O(1)
class Solution {
 public:
  bool checkInclusion(std::string s1, std::string s2) {
    int ns1 = s1.size();
    int ns2 = s2.size();
    if (ns1 > ns2)
      return false;
    std::vector<int> org(26, 0);
    for (int i = 0; i <= ns1; ++i)
      org[s1[i]-'a']++;
    for (int i = 0, j = 0; i <= ns2 - ns1; i += j) {
      std::vector<int> cnt(org);
      j = 0;
      while (j < ns1 && i + j < ns2) {
        int k = s2[i+j] - 'a';
        // printf("i: %d, j: %d, i+j: %d, cnt[k]:%d\n", i, j, i+j, cnt[k]);
        ++j;
        if (--cnt[k] < 0)
          break;
        if (i + j == i + ns1)
          return true;
      }
      // printf(",,i: %d\n", i);
    }
    return false;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "True" : "False");
}

int main() {
  Solution sln;
  printb(sln.checkInclusion("ab", "eidbaooo"));
  printb(sln.checkInclusion("ab", "eidboaoo"));
  
  return 0;
}
