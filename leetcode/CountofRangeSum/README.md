# Problem

[Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/)

# Idea

수열 `A[]` 와 하한 값 `lower`, 상한 값 `upper` 가 주어진다. `A` 의
부분수열 중 그 합의 범위가 `[lower, upper]` 를 만족하는 것들의 개수를
구하는 문제이다.

예를 들어, `A = [-2, 5, -1], lower = -2, upper = 2` 의 경우를 살펴보자.
[partial sum](/fundamentals/partialsum/partialsum/README.md) 을 이용해서 접근해 보자.

```cpp
  A: -2  5 -1
cnt: 0

for (int i = 0; i < n; i++) {
  ps[i+1] = ps[i] + A[i];
}
           i
ps:  0 -2  3  2
              j

for (int i = 0; i < A.size(); i++) {
  for (int j = i+1; j <= A.size(); j++) {
    int sum = ps[j] - ps[i];
    if (sum >= lower && sum <= upper) {
      cnt++;
    }
  }
}

cnt = 2
```

만약 `ps` 가 정렬되어 있다면 인덱스의 차이를 이용해서 손 쉽게 부분수열의 개수를 구할 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(lgN)
```
