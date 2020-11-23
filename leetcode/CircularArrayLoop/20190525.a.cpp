/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// Time: O(N), Space: O(1)
// I think [2 -1 1 -2 -2] should be true

class Solution {
 private:
  // get inex of vector V using delta d
  int next(std::vector<int>& V, int i) {
    int n = V.size();
    int d = V[i];
    int j = (i + d) % n;
    if (j < 0)
      j = n + j;
    return j;
  }
 public:
  bool circularArrayLoop(std::vector<int>& V) {
    int n = V.size();
    int slow = 0;
    int fast = 0;
    int cnt = 0;
    while (cnt < V.size()) {
      slow = next(V, slow);
      fast = next(V, next(V, fast));
      if (slow == fast &&
          next(V, slow) != slow &&
          next(V, next(V, slow)) != slow)
        return true;
      cnt++;
    }

    return false;
  }

  // void printnexts(std::vector<int>& V) {
  //   for (int i = 0; i < V.size(); ++i) {
  //     printf("%d ", next(V, i));
  //   }
  //   printf("\n");
  // }
};

//      s
//        f
// 2 -1 1 2 2
// 2  0 3 0 1
//       

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

//  f
//  s
//  2 -1 1 -2 -2
//          c
int main() {
  // std::vector<int> V = {2, -1, 1, 2, 2};
  // std::vector<int> V = {-1, 2};
  // std::vector<int> V = {-2, 1, -1, -2, -2};
  std::vector<int> V = {2, -1, 1, -2, -2};

  Solution sln;
  // sln.printnexts(V);
  printb(sln.circularArrayLoop(V));

  return 0;
}
