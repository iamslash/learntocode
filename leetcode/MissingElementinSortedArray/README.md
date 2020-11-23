# Problem

[Missing Element in Sorted Array](https://leetcode.com/problems/missing-element-in-sorted-array/)

# Idea

수열 `A[]` 와 숫자 `k` 가 주어진다. `A` 에서 `k` 번째
없는 숫자를 찾는 문제이다.

예를 들어 `A = [4, 7, 9, 10], k = 1` 를 살펴보자. `4` 과 `7` 사이에 `2` 개의 숫자 `(4, 7)` 가 있고  두개의
숫자 `(5, 6)` 가 없다. 답은 `5` 이다.

```
A: 4 . . 7
```

다음은 `A = [4, 7, 9, 10], k = 3` 를 살펴보자. `4` 과 `9` 사이에 `3` 개의 숫자 `(4, 7, 9)` 가 있고  `3` 개의
숫자 `(5, 6, 8)` 가 없다. 답은 `8` 이다.

```
A: 4 . . 7 . 9
```

위의 예를 보고 몇 가지 규칙을 발견할 수 있다.

* 특정 숫자 `A[i]` 의 왼편 즉 `A[i]` 보다 작은 감춰진 숫자의 개수는 `A[i] - i - A[0]` 이다. 그리고 이것을 `h` 라 하자.
* `k <= h` 이면 답은 `A[i]` 보다 작다. `k > h` 이면 답은 `A[i]` 보다 크다.

[Binary Search](https://github.com/iamslash/learntocode/blob/master/fundamentals/search/binarysearch/README.md) 로 해결할 만 하다.

```c
while (lo < hi) {
  int mi = (lo + hi) / 2;
  if (A[mi] >= A[0] + mi + k - 1)
    hi = mi;
  else
    lo = mi + 1;
}
```

마지막에 `A[0] + lo + k - 1` 이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(1)
```
