# Problem

[Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

# Idea

두개의 문자열 `A, B` 가 주어진다. longest common sequence 의
길이를 구하는 문제이다.

예를 들어 `A = abcde, B = ace` 를 살펴보자.  먼저 `int h = A.size(),
int w = B.size()` 라고 하자.  캐시 `vector<vector<int>> C(h+1,
vector<int>(w+1))` 를 선언하고 다음과 같이 채워나간다.

```
  0 a b c d e
0 0 0 0 0 0 0
a 0 1 1 1 1 1
c 0 1 1 2 2 2
e 0 1 1 2 2 3
```

다음과 같은 dynamic programming euqation 을 발견할 수 있다.

```
if (A[y-1][x-1] == B[y-1][x-1])
  C[y][x] = C[y-1][x-1] + 1
else
  C[y][x] = max(C[y-1][x], C[y][x-1])
```

`C[h][w]` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(HW)
```
