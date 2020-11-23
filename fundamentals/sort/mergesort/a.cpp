#include <cstdio>
#include <cstdlib>
#include <vector>

void printv(const std::vector<int>& v) {
  for (int a : v)
    printf("%d ", a);
  printf("\n");    
}

//
// l
//       r
//   m
// 1 3 4 5
//         i
//     j
//         k
void merge(int step, std::vector<int>& V, std::vector<int>& W,
           int l, int m, int r) {
  int i = l, j = m+1, k = l;
  while (i <= m && j <= r) {
    if (V[i] <= V[j])
      W[k++] = V[i++];
    else
      W[k++] = V[j++];
  }
  if (i > m) {
    for (int n = j; n <= r; ++n)
      W[k++] = V[n];
  } else {
    for (int n = i; n <= m; ++n)
      W[k++] = V[n];
  }
  std::copy(W.begin()+l, W.begin()+r+1, V.begin()+l);

  // for (int i = 0; i < step; ++i)
  //   printf("=");
  // printf("%d %d | ", l, r);
  // for (int i = l; i <= r; ++i)
  //   printf("%d ", W[i]);
  // printf("\n");
  
}

//         r
//     m
// l
// 1 4 7 0 9
//       i
//         j

//         k
// 0 1 4 7 
void msort(int step, std::vector<int>& V, std::vector<int>& W,
           int l, int r) {
  // for (int i = 0; i < step; ++i)
  //   printf("_");
  // printf("%d %d | ", l, r);
  // for (int i = l; i <= r; ++i)
  //   printf("%d ", V[i]);
  // printf("\n");

  // base condition
  if (l >= r)
    return;

  // recursion
  int m = (l+r)/2;
  msort(step+1, V, W, l, m);
  msort(step+1, V, W, m+1, r);
  merge(step, V, W, l, m, r);
}

void merge_sort(std::vector<int>& V) {
  std::vector<int> W = V;
  msort(0, V, W, 0, V.size()-1);
}

int main() {
  std::vector<int> V = {1, 1, 0, 3, 4, 5, 1, 0, 5, 5, 3, 1, 2, 2, 2, 2};
  
  merge_sort(V);
  
  printv(V);
  
  return 0;
}
