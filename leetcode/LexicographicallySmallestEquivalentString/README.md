# Problem

[Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/)

# Idea

문자열 `A, B, S` 가 주어진다. `A[i]` 와 `B[i]` 는 같은 집합에 속한다.
`S[i]` 를 그 문자가 속한 집합에서 사전순으로 가장 앞에 오는 문자로
교체한다. 모두 교체된 `S` 를 구하는 문제이다.

`A[i]` 와 `B[i]` 를 같은 집합으로 한다.  그리고 `S[i]` 가 속한 집합의
사전순 가장 앞의 오는 문자를 구해서 다시 `S[i]` 에 저장한다.  `S` 가
곧 답이다.

[DisjointSet](https://github.com/iamslash/learntocode/blob/master/fundamentals/disjointset/unionfind/README.md) 을 이용하여 해결한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(max(A,B)) O(N)
```
