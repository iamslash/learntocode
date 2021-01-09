#include <cstdio>
#include <vector>

using namespace std;

//    l       m         r
//              i
// A: 0 1 4 7 9 2 4 4 8 8
//                        j                    
//                        k
// W: 0 1 2 4 4 4 7 8 8 9
//    
// 

class Solution {
 private:
  void merge(vector<int>& A, vector<int>& W, 
              int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
      if (A[i] <= A[j]) {
        W[k++] = A[i++];
      } else {
        W[k++] = A[j++];
      }
    }
    if (i > m) {
      for (int o = j; o <= r; ++o) {
        W[k++] = A[o];
      }
    } else {
      for (int o = i; o <= m; ++o) {
        W[k++] = A[o];
      }
    }
    copy(W.begin()+l, W.begin()+r+1, A.begin()+l);
  }
  void _sort(vector<int>& A, vector<int>& W, 
              int l, int r) {
    // base
    if (l >= r) {
      return;
    }
    // recursion
    int m = (l + r) / 2;
    _sort(A, W, l, m);
    _sort(A, W, m+1, r);
    merge(A, W, l, m, r);
  }
 public:
  void sort(vector<int>& A) {
    vector<int> W = A;
    _sort(A, W, 0, A.size()-1);
  }
};

void printV(const vector<int>& A) {
  for (int a : A) {
    printf("%d ", a);
  }
  printf("\n");
}

int main() {
  Solution sln;
  std::vector<int> A = {1, 1, 0, 3, 4, 5, 1, 0, 5, 5, 3, 1, 2, 2, 2, 2};
  
  printV(A);
  
  sln.sort(A);
  printV(A);

  return 0;
}
