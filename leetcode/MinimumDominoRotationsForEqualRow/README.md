# Problem

[Minimum Domino Rotations For Equal Row](https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/)

수열 `A[], B[]` 가 주어진다. `A[i], B[i]` 를 서로 교체할 수 있다.
`A[]` 혹은 `B[]` 의 모든 원소들이 같은 값을 갖도록 최소 교체횟수를
구하라.

# Idea

예를 들어 `A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]` 를 살펴보자.

```
A: 2 1 2 4 2 2
B: 5 2 6 2 3 2
2:   .   .
```

따라서 답은 `2` 이다.

`A[]` 혹은 `B[]` 를 모두 같은 숫자로 만들 때 그 숫자를 `v` 라고 하자.
`v` 는 `A[0]` 혹은 `B[0]` 이다. 또한 `v` 는 `0 <= i < n` 일 때 `(A[i],
B[i])` 에 포함되야 한다.

그렇다면 교체횟수는 다음과 같이 구할 수 있다.

```
cnt = len(A) - max(count of v in A[], count of v in B[])
```

# Implementation

* [c++11](a.cpp)
* [python3](a.py)

# Complexity

```
O(N) O(1)
```
