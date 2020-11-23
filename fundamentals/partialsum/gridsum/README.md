# Abstract

- y1, x1, y2, x2 (y1 < y2, x1 < x2) 에 속하는 영역의 합

# Implementation

- 이차원 부분합(psum[][])을 미리 계산하자. psum[y1-1][x2]와
  psum[y2][x1-1]을 제거하자. 두번 제거 되었기 때문에
  psum[y1-1][x1-1]을 한번 더하자.

```cpp
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

  printf("%d\n", GridSum(PartialSum(a), 2, 4, 2, 4));
  return 0;
}
```
