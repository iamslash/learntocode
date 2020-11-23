# Problem

[Number of Subsequences That Satisfy the Given Sum Condition](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/)

수열 `A[]` 와 숫자 `t` 가 주어진다.  `A[]` 의 subsequence 를 선택한다.
subsequence 의 최소값과 최대값의 합이 `t` 보다 작도록 subsequence 를
골라보자. 그 개수를 구하는 문제이다.

# Idea

`A[]` 를 오름차순으로 정렬한다. 두개의 인덱스 `i = 0, j = n-1` 을 선언한다.
`A[i] + A[j] <= t` 인 `A[i..j]` 가 곧 subsequence 와 같다.

예를 들어 `A = [3, 5, 6, 7], t = 9` 인 경우를 살펴보자.  만약 `i=0,
j=3` 인 경우 `A[i] + A[j] <= 9` 이다.  숫자의 개수는 4 개 이고 `A[0]`
를 제외한 `A[1..3]` 으로 만들 수 있는 부분집합에 `A[0]` 를 끼워넣으면
조건을 만족하는 subsequence 가 된다.

이제 `i` 늘리고 `j` 를 줄여가면서 부분집합의 개수를 모두 합하면
답이된다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
