# Abstract

- partial sum(부분합)과 range sum(구간합)에 대해 적는다.

# partial sum

- 부분합을 미리 만들어 두면 구간합을 쉽게 구할 수 있다.
- psum[0] = a[0]             (i == 0)
- psum[i] = psum[i-1] + a[i] (i => 1)

```cpp
std::vector<int> PartialSum(const std::vector<int>& a) {
  std::vector<int> r(a.size());
  r[0] = a[0];
  for (int i = 1; i < a.size(); ++i) {
    r[i] = r[i-1] + a[i];
  }
  return r;
}
```

# range sum

- a 인덱스부터 b 인덱스 까지의 구간합은 부분합을 이용하여 구할 수 있다.
- rsum(a, b) = psum[b] - psum[a-1]

```cpp
int RangeSum(const std::vector<int>& psum, int a, int b) {
  if ( a == 0)
    return psum[b];
  return psum[b] - psum[a - 1];
}
```
