#include <cstdio>
#include <vector>

using namespace std;

//       i
// 1 2 3 5 4
//     p
//   j
//

class Solution {
 public:
  void sortHoare(vector<int>& A, int l, int r) {
    int i = l, j = r;
    int v = A[(l+r)/2];
    // base, conquer, partitioning
    while (i <= j) {
      while (A[i] < v) {
        ++i;
      }
      while (A[j] > v) {
        --j;
      }
      if (i <= j) {
        swap(A[i++], A[j--]);
      }
    }
    // recursion, divide
    if (l < j) {
      sortHoare(A, l, j);
    }
    if (i < r) {
      sortHoare(A, i, r);
    }
  }

//            i
// A: 2 1 3 4 5
//        p 
//   
//

  int partLomuto(vector<int>& A, int l, int r) {
    int partVal = A[r];
    int partIdx = l;

    for (int i = l; i < r; ++i) {
      if (A[i] < partVal) {
        swap(A[i], A[partIdx++]);
      }
    }
    swap(A[partIdx], A[r]);

    return partIdx;
  }

  void sortLomuto(vector<int>& A, int l, int r) {
    // base
    if (l >= r) {
      return;
    }
    // recursion
    int p = partLomuto(A, l, r);
    sortLomuto(A, l, p-1);
    sortLomuto(A, p+1, r);
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
  vector<int> A = {5, 4, 3, 2, 1};
  printV(A);
  sln.sortHoare(A, 0, A.size()-1);
  printV(A);
  sln.sortLomuto(A, 0, A.size()-1);
  printV(A);

  return 0;
}
