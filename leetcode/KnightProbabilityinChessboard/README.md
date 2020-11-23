# Problem

[Knight Probability in Chessboard](https://leetcode.com/problems/knight-probability-in-chessboard/)

숫자 `N, K, r, c` 가 주어진다. Knight 를 `G[r][c]` 에서 시작하여 `K`
번 움직여 본다. 모든 경우의 수를 고려해 보자. Knight 가 Board 밖으로 나가지
않고 Board 안에 머무를 수 있는 확률을 구하라.

# Idea

Knight 이 `G[y][x]` 에 있을 때 8 방향으로 전진할 수 있다. 다음과 같이 `dy[8], dx[8]`
를 정의한다.

```
int dy[8] = {-2,-1,1,2, 2, 1,-1,-2};
int dx[8] = { 1, 2,2,1,-1,-2,-2,-1};
```

memoization 을 위해 캐쉬 `C[K+1][N][N]` 를 선언한다.

다음과 같이 부분문제 `dfs` 를 정의한다.

```
double dfs(C, int k, int y, int x)

return: probability of k, y, x
     C: cache for k, y, x
     k: remained count
     y: y of G[y][x]
     x: x of G[y][x]
```

G[y][x] 에 방문하면 G[y][x] 를 중심으로 8 방향으로 전진한다. 이때
BAORD 밖으로 나가지 않은 경우를 1 로 생각한다. 만약 모두 나가지 않았다면
경우의 수의 합은 8 이고 확률은 1.0 이다. 한 경우만 나가지 않았다면 
경우의 수의 합은 1 이고 확률은 1/8.0 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(KN^2) O(KN^2)
```
