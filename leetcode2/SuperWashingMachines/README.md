# Problem

[Super Washing Machines](https://leetcode.com/problems/super-washing-machines/)

수열 `M[]` 가 주어진다. 임의의 `M[i]` 를 골라서 왼쪽 오른쪽으로 숫자
하나를 이동시킬 수 있다. 모든 `M[i]` 가 같아지도록 최소한의 이동횟수를
구하라.

# Idea

`int total` 을 선언하여 `M[]` 를 모두 더하라. `int avg` 를 선언하여
`total / M.size()` 를 저장한다. 만약 `total % M.size() != 0` 이면 `-1`
를 리턴한다.

`int sum` 을 선언하여 왼쪽에서 오른쪽으로 이동해야할 횟수를 저장한다.

이제 인덱스 `i` 를 이용하여 `M[]` 를 처음부터 끝까지 순회하며 다음을
반복한다.

* `sum += M[i] - avg` 를 수행한다. `M[i] - avg` 는 `M[i]` 에서
  오른쪽으로 이동해야할 수를 의미한다.
* `ans = max(ans, max(abs(sum), M[i] - avg))` 를 수행한다.

```
//   M: 1 0 5
//          m
// avg: 2
// sum:-1-3 0
// ans: 1 3 3

//   M: 0 3 0
//          m
// avg: 1
// sum:-1 1 0
// ans: 1 2 2

```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
