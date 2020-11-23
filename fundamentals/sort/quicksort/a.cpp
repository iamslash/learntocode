#include <cstdio>
#include <cstdlib>
#include <vector>

void printv(const std::vector<int>& v) {
  for (int a : v)
    printf("%d ", a);
  printf("\n");    
}

void qsort_h(int step, std::vector<int>& v, int l, int r) {
  int i = l, j = r;
  int pv = v[(l+r)/2];

  // partition
  while (i <= j) {
    while (v[i] < pv)
      ++i;
    while (v[j] > pv)
      --j;
    if (i <= j)
      std::swap(v[i++], v[j--]);
  }

  // for (int k = 0; k < step; ++k)
  //   printf("_");
  // printf("l:%d, r: %d, i: %d, j: %d | ", l, r, i, j);
  // for (int k = l; k <= r; ++k)
  //   printf("%d ", v[k]);
  // printf("\n");

  if (l < j)
    qsort_h(step+1, v, l, j);
  if (i < r)
    qsort_h(step+1, v, i, r);

}

int part_l(std::vector<int>& v, int l, int r) {
  int pv = v[r];
  int rr = l;

  for (int i = l; i < r; ++i)
    if (v[i] < pv)
      std::swap(v[i], v[rr++]);
  std::swap(v[rr], v[r]);
  
  return rr;
}

void qsort_l(std::vector<int>& v, int l, int r) {
  // base condition
  if (l >= r)
    return;
  // recursion
  int p = part_l(v, l, r);
  qsort_l(v, l, p-1);
  qsort_l(v, p+1, r);
}

int main() {
  // std::vector<int> V = {1, 1, 0, 3, 4, 5, 1, 0, 5, 5, 3, 1, 2, 2, 2, 2};
  std::vector<int> V = {5, 3, 7, 6, 2, 1, 4};
  
  qsort_h(0, V, 0, V.size()-1);
  printv(V);

  // V = {1, 1, 0, 3, 4, 5, 1, 0, 5, 5, 3, 1, 2, 2, 2, 2};

  // qsort_l(V, 0, V.size()-1);
  // printv(V);
  
  return 0;
}
