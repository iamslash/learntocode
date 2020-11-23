/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

//              0
//          /       \
//        1          2
//      /   \      /   \
//     3     4    5     6
//    / \   / \  / \   / \
//   7   8 9  1011 12 13 14

//                3
//                  \
//                   9
//                     \
//                      9
//                     / \
//                    0   5
// 21 + 26
//

// 4ms 95.57% 8.8MB 54.13%
// O(N) O(N)
class Solution {
 private:
  std::vector<int> m_tree;
 public:
  int pathSum(std::vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0] % 10;
    m_tree = std::vector<int>(16, -1);
    for (int a : nums) {
      std::string s = std::to_string(a);
      int dpt = s[0] - '0';
      int pos = s[1] - '0';
      int val = s[2] - '0';
      int i = std::pow(2, dpt-1) - 1 + pos - 1;
      m_tree[i] = val;
      m_tree[i] += i > 0 ? m_tree[(i-1)/2] : 0;
    }
    // for (int a : m_tree)
    //   printf("%3d ", a);
    // printf("\n");
    int sum = 0;
    for (int i = 0; i < 15; ++i) {
      if ((i >= 7 && m_tree[i] >= 0) ||
          (m_tree[i] >= 0 && m_tree[2*(i+1)-1] < 0 && m_tree[2*(i+1)] < 0)) {
        // printf("%d\n", i);
        sum += m_tree[i];
      }
    }
    return sum;
  }
};

int main() {
  // std::vector<int> V = {113, 215, 221};
  // std::vector<int> V = {111,217,221,315,415};
  // std::vector<int> V = {113};
  std::vector<int> V = {113, 229, 349, 470, 485};
  // std::vector<int> V = {110, 218, 315, 326, 423, 433};
  Solution sln;
  printf("%d\n", sln.pathSum(V));
  return 0;
}
