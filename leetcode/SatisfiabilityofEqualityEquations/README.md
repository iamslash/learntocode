# Problem

[Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)

# Idea

네개의 문자들로 구성된 식들의 모음 `E[]` 가 주어진다. `E[i][0]`
과 `E[i][3]` 의 문자에 대응하는 숫자를 삽입했을 때 전체 식이
옳바른지 검증하는 문제이다. `E[i][1..2]` 는 `!=` 혹은 `==`
뿐이다. 또한 `E[i][0], E[i][3]` 은 영문 소문자 뿐이다.

`!=` 와 `==` 만 비교하면 된다. 영문 소문자들을 그룹화 하면 될 것 같다.
DisjointSet 으로 해결할 만 하다.

DisjointSet 을 만들고 `E[]` 를 순회하면서 `E[i][1..2] == '=='`
일 때 `merge(E[i][0], E[i][1])` 를 수행한다.

그리고 다시 `E[]` 를 순회하면서 `E[i][1..2] == '!='` 일 때
`find(E[i][0]) == find (E[i][1])` 일 때 `false` 를 리턴한다.

모든 반복을 마치면 `true` 를 리턴한다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
