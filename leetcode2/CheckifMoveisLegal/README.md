# Problem

[Check if Move is Legal](https://leetcode.com/problems/check-if-move-is-legal/)

이차원 `board[][]`, 숫자 `r, c, color` 가 주어진다.  `board[][]` 는
`B, W, .` 으로만 구성되어 있고 각각 검정색, 흰색, 빈 셀을
의미한다. 크기는 `8 x 8` 이다. `board[r][x]` 로 부터 8 방향으로 탐색을
한다. good line 이 있는지 검증하라.

good line 은 양끝은 같은 색이고 중간만 다른 색인 셀의 모음을 말한다.

# Idea

다음과 같이 8 방향을 `dirs[][]` 으로 선언한다.

```java
int[][] dirs = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
```

이제 각 방향에 대해 탐색을 한다. 양 끝은 같고 중간만 다른 셀의 모음이
있다면 true 를 리턴한다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(1) O(1)
```
