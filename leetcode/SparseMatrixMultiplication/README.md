# Problem

[Sparse Matrix Multiplication](https://leetcode.com/problems/sparse-matrix-multiplication/)

2차원 배열 `mat1, mat2` 가 주어진다. `mat1, mat2` 는
0 을 많이 포함하고 있다. `mat1 x mat2` 를 구하라.

# Idea

예를 들어 `2 X 3, 3 X 3` 행렬의 곱셈을 생각해 보자.
답은 `2 X 3` 모양의 행렬이다.

```
 1 0 0   7 0 0    7 0 0
-1 0 3   0 0 0   -7 0 3
         0 0 1
```

왼쪽 행렬 원소의 값이 0 이면 그 값을 이용하는 연산은 더이상 의미가
없다. 왼족 행렬 원소의 값을 기준으로 행렬의 곱셈 연산을 다시 생각해
보자. 왼쪽 행렬 원소의 값을 기준으로 오른쪽 행렬의 한 행을 구성하는
원소들이 곱하여 답행열의 한 행을 구성하는 원소들에 더해지는 형태이다.

`mat1` 이 `m X n` 의 모양이고 `mat2` 는 `n X w` 의 모양이라고 해보자.

다음과 같은 3 중 loop 를 생각해 볼 수 있다.

```java
for (int y = 0; y < m; ++y) {
  for (int x = 0; x < n; ++x) {
    if (mat1[y][x] == 0) {
      continue;
    }
    for (int j = 0; j < w; ++j) {
      if (mat2[x][j] == 0) {
        continue;
      }
      ans[y][j] += mat1[y][x] * mat2[x][j];
    }
  }
}
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(MNW) O(MW)

mat1: M X N
mat2: N X W
```
