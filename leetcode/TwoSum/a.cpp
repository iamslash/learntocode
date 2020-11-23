#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

//     j
// i 
// 2 3 4

// 16ms 58.60% 10.3MB 40.66%
// Q. what is the range of I.size()? integer
// Q. what is the range of I[i]? integer
// Q. I is already sorted? no
// O(1) O(N)
class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& I, int tgt) {
    std::unordered_map<int, int> ump;
    for (int i = 0; i < I.size(); ++i) {
      int a = I[i];
      int b = tgt - a;
      if (ump.count(b)) {
        int j = ump[b];
        return {j, i};
      }
      ump[a] = i;
    }
    return {};
  }
};

//  i  j 
// -5 -4 -3 -2 -1
int main() {
  //std::vector<int> I = {2, 7, 11, 15};
  //int tgt = 9;
  //std::vector<int> I = {3, 2, 4};
  //int tgt = 6;
  //std::vector<int> I = {3, 3};
  //int tgt = 6;
  //std::vector<int> I = {0, 4, 3, 0};
  //int tgt = 0;
  std::vector<int> I = {-1,-2,-3,-4,-5};
  int tgt = -8;
  Solution sln;
  auto r = sln.twoSum(I, tgt);
  printf("%d %d\n", r[0], r[1]); 
  return 0;
}
