// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdint>
#include <vector>

std::vector<std::vector<int> > PartialSum(const std::vector<std::vector<int> >& a) {
  std::vector<std::vector<int> > r(a);
    
  for (int y = 0; y < a.size(); ++y) {
    for (int x = 0; x < a[y].size(); ++x) {
      if (x > 0)
        r[y][x] += r[y][x-1];
      if (y > 0)
        r[y][x] += r[y-1][x];        
    }
  }

  return r;
}

void PrintPartialSum(const std::vector<std::vector<int> >& psum) {
  for (int y = 0; y < psum.size(); ++y) {
    for (int x = 0; x < psum[y].size(); ++x) {
      printf("%2d ", psum[y][x]);
    }
    printf("\n");
  }  
}

int GridSum(const std::vector<std::vector<int> >& psum, int y1, int x1,
            int y2, int x2) {
  int r = psum[y2][x2];

  if (y1 > 0)
    r -= psum[y1-1][x2];
  if (x1 > 0)
    r -= psum[y2][x1-1];
  if (y1 > 0 && x1 > 0)
    r += psum[y1-1][x1-1];
  
  return r;
}

int main()
{
  std::vector<std::vector<int> > a = {{1,1,1,1,1},
                                      {1,1,1,1,1},
                                      {1,1,1,1,1},
                                      {1,1,1,1,1},
                                      {1,1,1,1,1}};

  std::vector<std::vector<int> > pasum;
  // PrintPartialSum(PartialSum(a));  
  printf("%d\n", GridSum(PartialSum(a), 2, 4, 2, 4));

  return 0;
}
