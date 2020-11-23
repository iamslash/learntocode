# Problem

[Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/)

# Idea

그래프의 정보 `G[][]` 가 주어진다. 그래프의 각 셀은 `0, 1` 로만
구성되어 있다. 벽에 인접하지 않고 `1` 로만 구성된 컴포넌트를 찾아서
`1` 의 개수를 구하는 문제이다.

DFS 를 이용하여 벽에 붙어 있는 컴포넌트들의 각 셀을 모두 `0` 으로
바꾼다.

`G[][]` 를 순회하면서 `1` 의 개수를 구한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(WH) O(1)
```
