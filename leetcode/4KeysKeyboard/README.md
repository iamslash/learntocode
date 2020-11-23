# Problem

[4 Keys Keyboard](https://leetcode.com/problems/4-keys-keyboard/)

# Idea

숫자 `N` 이 주어진다. `A, C-A, C-C, C-V` 와 같이 4 종류의
키만 `A` 가 가장 많이 출력되었을 때 그 개수를 구하는 문제이다.

예를 들어 `N = 3` 일 때 `A, A, A` 이면 답은 `3` 이다.
또한 `N = 7` 일 때 `A, A, A, C-A, C-C, C-V, C-V` 이면 답은 `9` 이다.

dynamic programming 을 위해 다음과 같이 캐시를 선언한다.

```
vector<int> C(N+1)
C[i] : max count at i
```

인덱스 `i` 를 이용하여 `[0..N]` 을 순회하면서 다음을 반복한다.

0. `C[i] = i`
1. 인덱스 `j` 를 이용하여 `[1..i-3]` 을 순히화면서 다음을 반복한다.
  0. `C[i] = max(C[i], 'j 까지 A 를 하고 이후 i 까지 C-A, C-C, C-V, C-V,
     C-V... 했을 경우의 수'`

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
