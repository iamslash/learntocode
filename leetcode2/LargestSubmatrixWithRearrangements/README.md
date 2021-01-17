# Problem

[Largest Submatrix With Rearrangements](https://leetcode.com/problems/largest-submatrix-with-rearrangements/)

이차원 배열 `M[][]` 가 주어진다. `M[y][x]` 는 `0` 혹은 `1` 이다.
`M[][]` 의 서로 다른 열을 얼마든지 바꿀 수 있다.  인접한 `1` 로 구성된
rectangle 의 넓이가 최대가 되도록 열을 교체해 보자.  그때 최대
rectangle 의 넓이를 구하라.

# Idea

예를 들어 `M = [[0,0,1],[1,1,1],[1,0,1]]` 의 경우를 살펴보자.

```
M:       heights: sortedHeights:
0 0 1    0 0 1    0 0 1
1 1 1    1 1 2    1 1 2
1 0 1    2 0 3    0 2 3
```

`sortedHeights` 는 높이의 오름차순으로 정렬되어 있다.
다음과 같은 loop 을 이용하면 최대 넓이를 구할 수 있다.

```
for (int x = 0; x < w; ++x) {
  ans = Math.max(ans, (w - x) * sortedHeights[x]);
}
```

# Implementation

* [java8](Solution.java)

# Complexity

```
O(HWlgW) O(W)
```

# Similar Questions

* [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
* [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

