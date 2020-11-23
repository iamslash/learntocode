// Copyright (C) 2016 by iamslash

#include <string>
#include <vector>
#include <algorithm>

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

std::vector<int> GetPartialMatch(const std::string& n) {
  std::vector<int> r(n.size(), 0);

  for (int begin = 1; begin < n.size(); ++begin) {
    printf("begin: %d\n", begin);
    for (int i = 0; i < n.size(); ++i) {
      printf("  i: %d\n", i);
      // there is no match let's go to next begin
      if (n[i] != n[begin + i])
        break;
      r[begin + i] = std::max(r[begin + i], i + 1);
    }
  }

  return r;
}

std::vector<int> Kmp(const std::string& h, const std::string& n) {
  std::vector<int> r;
  
  int begin = 0;
  int matched = 0;
  std::vector<int> pi = GetPartialMatch(n);

  while (begin + matched <= h.size()) {
    // if match
    if (h[begin + matched] == n[matched]) {
      matched++;
      if (matched == n.size())
        r.push_back(begin);
    } else {
      
      if (matched == 0) {
        begin++;
      // 
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }

  return r;
}

int main() {
  // std::string h = "hellomynameisslashmynameisnotfoo";
  // std::string n = "myname";

  // std::vector<int> r = Kmp(h, n);

  // printf("%s\n", h.c_str());
  // printf("%s\n", n.c_str());
  // PrintVInt(r);
  //
  std::vector<int> r = GetPartialMatch("aabaabac");
  PrintVInt(r);
  
  return 0;
}
