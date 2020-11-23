# Problem

[Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)

수열 `A[]`, 숫자 `k` 가 주어진다. 임의의 `A[i], A[j] (i != j)` 를
선택하여 그 거리를 `dist` 라고 하자. k 번째로 큰 `dist` 를 구하라.

# Idea

`A[]` 를 오름차순으로 정렬 한다. `int lo, hi` 를 선언하여 각각 `lo =
min(abs(A[j]-A[i])) (i < j), hi = A[n-1] - A[0]` 를 저장한다.  binary
search 로 해결할 만 하다.

`int mi = lo + (hi - lo) / 2` 를 선언한다. `mi` 가 정해지면
`A[]` 의 짝들 중 거리가 `mi` 이하인 것들의 개수를 구하고 `k` 와 비교한다.

`A[]` 를 순회하면서 짝들의 거리가 `mi` 이하인 것은 sliding window
를 이용하여 `O(N)` 으로 구할 수 있다. 

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
