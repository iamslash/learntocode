#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//            i
// A: 1 2 3 4 5
//            j

// insertion sort
// O(N^2) O(1)
class Solution {
 public:
  void sort(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
      for (int j = i; j > 0 && A[j-1] > A[j]; --j) {
        swap(A[j-1], A[j]);
      }
    }
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
  sln.sort(A);
  printV(A);
}
