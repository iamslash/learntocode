# Problem

[Average Height of Buildings in Each Segment](https://leetcode.com/problems/average-height-of-buildings-in-each-segment/)

배열의 모음 `buildings[]` 가 주어진다. `buildings[i][0],
buildings[i][1], buildings[i][2]` 는 각 빌딩의 시작 위치, 끝 위치,
높이를 의미한다. 겹치는 부분을 고려하여 half-closed segment 들을
구하라.

# Idea

겹치는 부분을 고려한 half-closed segment 는 `[start, end, average
height]` 로 표기한다. 이때 half-closed segment 가 이어져있고 같은
`average height` 라면 merge 한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(N)
```
