// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdint>
#include <vector>

std::vector<int> PartialSum(const std::vector<int>& a) {
  std::vector<int> r(a.size());
  r[0] = a[0];
  for (int i = 1; i < a.size(); ++i) {
    r[i] = r[i-1] + a[i];
  }
  return r;
}

int RangeSum(const std::vector<int>& psum, int a, int b) {
  if ( a == 0)
    return psum[b];
  return psum[b] - psum[a - 1];
}

std::vector<int> SquarePartialSum(const std::vector<int>& a) {
  std::vector<int> r(a.size());
  r[0] = a[0] * a[0];
  for (int i = 1; i < a.size(); ++i) {
    r[i] = r[i-1] + a[i] * a[i];
  }
  return r;
}

double Variance(const std::vector<int>& sqpsum,
                const std::vector<int>& psum,
                int a, int b) {
  // get average value from a to b
  double mean = RangeSum(psum, a, b) / double(b - a + 1);
  double r = RangeSum(sqpsum, a, b) -
      2 * mean * RangeSum(psum, a, b)
      + (b - a + 1) * mean * mean;
  return r / (b - a + 1);
}

int main()
{
  std::vector<int> a = {1,2,3,4,5,6,7};

  std::vector<int> psum = PartialSum(a);
  printf("%f\n", Variance(SquarePartialSum(a), PartialSum(a), 2, 4));

  return 0;
}
