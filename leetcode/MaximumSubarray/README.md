# Problem

[Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

# Idea

수열 `A[]` 가 주어진다. 연속된 부분 수열중 가장 큰 합을 구하라.

[kadane's algorithm](/fundamentals/array/kadane/README.md) 을 참고한다.

다음과 같이 구현하면 `overflow` 를 피할 수 없다.

```cpp
class Solution {
 public:
  int maxSubArray(vector<int>& A) {
    int locMax = INT_MIN, glbMax = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
      locMax = std::max(locMax+A[i], A[i]);
      glbMax = std::max(locMax, glbMax);
    }
    return glbMax;        
  }
};
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
