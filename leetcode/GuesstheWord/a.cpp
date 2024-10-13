/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

class Master {
 public:
  int guess(std::string a) {
    std::string b = "acckzz";
    int r = 0;
    for (int i = 0; i < a.size(); ++i)
      if (a[i] == b[i])
        r++;
    return r;
  }
};

// 4ms 100.00%
// O(N) O(N)
class Solution {
 private:
  int match(std::string a, std::string b) {
    int r = 0;
    for (int i = 0; i < a.size(); ++i)
      if (a[i] == b[i])
        r++;
    return r;
  }
 public:
  void findSecretWord(std::vector<std::string>& W, Master& M) {
    for (int i = 0; i < 10; ++i) {
      int n = W.size();
      std::string s = W[rand() % n];
      int r = M.guess(s);
      std::vector<std::string> W2;
      for (auto& w : W) {
        if (match(s, w) == r)
          W2.push_back(w);
      }
      W = W2;
    }
  }
};

// 12ms 31.45% 8.9MB 51.61%
// O(N^2) O(N)
class Solution {
 private:
  int match(std::string a, std::string b) {
    int r = 0;
    for (int i = 0; i < a.size(); ++i)
      if (a[i] == b[i])
        r++;
    return r;
  }
 public:
  void findSecretWord(std::vector<std::string>& W, Master& M) {
    for (int i = 0; i < 10; ++i) {
      int n = W.size();
      // exclusive word : count
      // {string:distinct count,...}
      std::unordered_map<std::string, int> exwordcnt;
      for (auto& a : W) {
        for (auto& b : W) {
          if (match(a, b) == 0)
            exwordcnt[a]++;
        }
      }

      std::pair<std::string, int> minimax = {W[0], 1000};
      for (auto& a : W) {
        if (exwordcnt[a] <= minimax.second)
          minimax = {a, exwordcnt[a]};
      }

      // printf("%d - %s: %d\n", i, minimax.first.c_str(), minimax.second);
      // for (auto& k : exwordcnt) {
      //   printf("%s: %d, ", k.first.c_str(), k.second);
      // }
      // printf("\n");
            
      int r = M.guess(minimax.first);
      std::vector<std::string> W2;
      for (auto& a : W) {
        if (match(minimax.first, a) == r)
          W2.push_back(a);
      }
      W = W2;

      // printf("  ");
      // for (auto& a : W) {
      //   printf("%s ", a.c_str());
      // }
      // printf("\n");
    }
  }
};


int main() {

  std::vector<std::string> W = {
    "acckzz","ccbazz","eiowzz","abcczz"
  };
  Master M;
  
  Solution sln;
  sln.findSecretWord(W, M);
  
  return 0;
}
