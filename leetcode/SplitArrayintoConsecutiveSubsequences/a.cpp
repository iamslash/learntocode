/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

//    1 2 3 4 5
// f: 1 1 2 2 1
// t: 0 0 0 0 0
//    
//    i
// V: 1 2 3 3 4 4 5

// // 116ms 69.37% 18.1MB 49.20%
// // greedy algorithm
// // O(N) O(N)
// class Solution {
//  public:
//   bool isPossible(std::vector<int>& V) {
//     // freq[i]: counts of number i
//     // tail[i]: counts of continuous subsequnce ends with number i
//     std::unordered_map<int, int> freq, tail;
//     for (int i : V)
//       freq[i]++;
//     for (int i : V) {
//       if (freq[i] == 0)
//           continue;
//       if (tail[i-1] > 0) {
//         tail[i-1]--;
//         tail[i]++;
//       } else if (freq[i+1] && freq[i+2]) {
//         freq[i+1]--;
//         freq[i+2]--;
//         tail[i+2]++;
//       } else {
//         return false;
//       }
//       freq[i]--;
//     }
//     return true;
//   }
// };

//      
// cnts: 0 0 0 1
//  val: 1
//         i
//    V: 1 2 3
//
// How does it work???
// 80ms 98.65% 13.6MB 99.00%
// O(N) O(1)
class Solution {
 public:
  bool isPossible(std::vector<int>& V) {
    int cnts[4] = {0,}, i = 0, val = V[0], n = V.size();
    while (i < n) {
      while (i < n && V[i] == val) {
        ++cnts[3];
        ++i;
      }
      if (cnts[3] < cnts[1] + cnts[2])
        return false;
      int excess = cnts[3] - (cnts[0] + cnts[1] + cnts[2]);
      cnts[0] = cnts[1] + std::min(cnts[0], cnts[3] - (cnts[1] + cnts[2]));
      ctns[1] = cnts[2];
      cnts[2] = std::max(0, excess);
      cnts[3] = 0;
      ++val;
    }
    return cnts[1] == 0 && cnts[2] == 0;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "True" : "False");
}

int main() {
  std::vector<int> V = {1, 2, 3, 3, 4, 5};
  // std::vector<int> V = {1, 2, 3, 3, 4, 4, 5, 5};
  // std::vector<int> V = {1, 2, 3, 4, 4, 5};

  Solution sln;
  printb(sln.isPossible(V));
  
  return 0;
}
