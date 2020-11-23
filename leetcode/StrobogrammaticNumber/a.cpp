#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

// 0 1 2 3 4 5 6 7 8 9
// 0 1 x x x x 9 x 8 6  

// 4ms 100.00% 7.9MB 100.00%
// reverse and change a digit
// O(N) O(1)
class Solution {
 public:
  bool isStrobogrammatic(std::string num) {
    std::vector<int> V = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    std::string rnm = num;
    int i = 0, n = rnm.size(), half = (n+1)/2;
    while (i < half) {
      int j = n-i-1;
//printf("%d:%c %d, %d:%c %d\n", 
//  i, rnm[i], V[rnm[i]-'0'], j, rnm[j], V[rnm[j]-'0']);
      if (V[rnm[i]-'0'] < 0 || V[rnm[j]-'0'] < 0)
        return false;
      if (i == j) {
        rnm[i] = V[rnm[i]-'0'] + '0';
      } else {
        std::swap(rnm[i], rnm[j]);
        rnm[i] = V[rnm[i]-'0'] + '0';
        rnm[j] = V[rnm[j]-'0'] + '0';
      }
      ++i;
    }
//printf("%s\n", rnm.c_str());
    return rnm == num;      
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  Solution sln;
//  printb(sln.isStrobogrammatic("69"));
//  printb(sln.isStrobogrammatic("88"));
//  printb(sln.isStrobogrammatic("962"));
  printb(sln.isStrobogrammatic("6"));

  return 0;
}