#include <cstdio>
#include <vector>

// 4ms 100.00% 12.3MB 75.93%
// O(N) O(N)
class Solution {
 private:
  int solve(std::vector<NestedInteger>& V, int w) {
    int r = 0;
    for (auto& i : V) {
      r += i.isInteger() ? i.getInteger()*w : solve(i.getList(), w+1);
    }   
    return r;    
  }
 public:
  int depthSum(std::vector<NestedInteger>& V) {
    return solve(V, 1);
  }
};
