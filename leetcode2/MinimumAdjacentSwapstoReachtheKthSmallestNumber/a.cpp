/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//   k: 4
// num: 5489355142
//      5489355214
//      5489355241
//      5489355412
//               p
//      5489355421
//             i

// 24ms 94.01% 6.6MB 69.66%
// permutation, rotate
class Solution {
public:
  int getMinSwaps(string num, int k) {
    string prm = num;
    while (--k >= 0) {
      next_permutation(num.begin(), num.end());
    }
    int cnt = 0;
    for (int i = 0; i < num.size(); ++i) {
      if (prm[i] != num[i]) {
        auto pos = prm.find(num[i], i);
        cnt += pos - i;
        rotate(prm.begin()+i, prm.begin()+pos, prm.begin()+pos+1);
      }
    }
    return cnt;
  }
};

//   k: 4
//             i
// num: 5489355142
// prm: 5489355421
//               j

// 32ms 74.91% 40.2MB 9.24%
class Solution {
public:
  int getMinSwaps(string num, int k) {
    string prm = num;
    while (--k >= 0) {
      next_permutation(prm.begin(), prm.end());
    }    
    int cnt = 0;
    for (int i = 0; i < num.size(); ++i) {
      if (num[i] != prm[i]) {
        for (int j = i + 1; j < num.size(); ++j) {
          if (num[i] == prm[j]) {
            cnt += j - i;
            prm = prm.substr(0, i+1) +
                prm.substr(i, j-i) +
                prm.substr(j+1);
            break;
          }
        }
      }
    }
    return cnt;
  }
};

void printV(const vector<int>& A) {
  for (int a : A) {
    printf("%d ", a);
  }
  printf("\n");
}

int main() {
  vector<int> A;
  for (int i = 1; i < 10; ++i) {
    A.push_back(i);
  }
  // 1 2 3 4 5 6 7 8 9 10
  printV(A);
  rotate(A.begin(), A.begin()+2, A.begin()+5);
  // 3 4 5 1 2 6 7 8 9 10
  printV(A);
  return 0;
}
