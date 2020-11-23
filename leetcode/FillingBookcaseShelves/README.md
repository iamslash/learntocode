# Problem

[Filling Bookcase Shelves](https://leetcode.com/problems/filling-bookcase-shelves/)

# Idea

책의 넓이 높이의 모음 `B[][]` 가 주어진다. 그리고 책장의 넓이 `W` 가
주어진다. 책장의 넓이를 초과하지 않고 모든 책을 순서대로 배치했을 때
총 높이가 최소가 되도록 해보자. 그때의 높이를 구하는 문제이다.

잘 생각해 보면 책들을 넓이가 `W` 가 초과되지 않도록 파티셔닝하는
문제이다. `B[i]` 를 이번 선반에 배치했을 때와 다음 선반에 배치했을 때
총 높이를 구해서 최소를 선택하면 되는 문제이다. 충분히 dynamic
programming 으로 해결할 만하다.

먼저 캐시 `C[][]` 를 선언하여 `C[book index][previous sum of book widths] =
min total height` 를 저장하자.

그리고 다음과 같은 부분문제를 정의하고 재귀적으로 구현해 보자.

```
int dfs(int i, int w, int h)
     i: 이번에 배치할 책의 인덱스
     w: 이번에 배치할 선반에서 지금까지 배치한 책들의 넓이 
     h: 이번에 배치할 선반에서 지금까지 배치한 책들의 최고 높이
return: total height
```

* `i >= B.size()` 이면 `h` 를 리턴한다.
* `C[i][w] != 0` 이면 `C[i][w]` 를 리턴한다.
* 다음 선반에 `B[i]` 를 배치한 경우 저네 높이를 `nextshelf` 에 저장한다.
  * `nextshelf = h + dfs(i+1, B[i][0], B[i][1])`
* 이번 선반에 `B[i]` 를 배치할 수 있는 경우 전체 높이를 `thisshelf` 에
  저장한다. 이번 선반에 `B[i]` 를 배치할 수 없다면 `thisshelf =
  INT_MAX` 를 수행한다.
  * `thisshelf = dfs(i+1, w+B[i][0], max(h, B[i][1]))`
* `C[i][w]` 에 `min(thisshelf, nextshelf)` 를 저장한다.
* `C[i][w]` 를 리턴한다.

`dfs(0, 0, 0)` 이 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
