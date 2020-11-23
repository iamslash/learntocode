# Problem

[Coloring A Border](https://leetcode.com/problems/coloring-a-border/)

# Idea

그리드의 정보 `G[][]` 와 시작 위치 `r, c` 그리고 색 `col` 이 주어진다.
`r, c` 위치부터 시작하여 같은 색으로 이루어 진 컴포넌트의 경계를 `col`
로 칠하는 문제이다.

다음과 같은 부분문제 `dfs` 를 정의하고 `r, c` 부터 시작하여 같은 컴포넌트의
셀들을 모두 음수로 전환한다. 

```cpp
void dfs(vector<vector<int>> &G, int y, int x, int col)

  G: 그래프
  y: y 좌표
  x: x 좌표
col: 테두리를 칠해야할 색
```

`dfs` 함수 안에서 `DFS loop` 를 끝내면 현재 방문한 위치가 컴포넌트의 
경계가 아니라면 음수에서 원래 색으로 돌려 놓는다.

`dfs` 를 마치면 `G[][]` 를 순회하면서 음수인 색을 `col` 로
변경한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
