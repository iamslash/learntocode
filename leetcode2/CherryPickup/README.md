# Problem

[Cherry Pickup](https://leetcode.com/problems/cherry-pickup/)

이차원 배열 `G[][]` 가 주어진다. `G[i]` 는 `0, -1, 1` 로 구성되어
있다. `0, 1` 은 체리의 개수를 의미하고 지나갈 수 있다. `-1` 은
가시밭을 의미하고 지나갈 수 없다.

`G[0][0]` 에서 시작하여 `G[n-1][n-1]` 로 이동한다. 그리고 다시
`G[0][0]` 으로 돌아온다. 수집한 체리의 개수가 최대가 되도록 이동하고
그 체리의 개수를 구하라.

# Idea

`G[0][0]` 에서 출발하여 `G[n-1][n-1]` 까지 이동할 때 두명이 움직인다고
생각해 보자. 두 명 `a, b` 에 대해 다음과 같은 경우의 수가 존재한다.

```
a      b
down   down
down   right
right  down
down   right
```

다음과 같은 부분문제 `dfs` 를 정의하고 재귀적으로 해결한다.

```
int dfs(vector<vector<vector>>>& C, vector<vector<int>>& G,
  int y1, x1, x2)
  
return: max cherries
     C: cache for y1, x1, x2
     G: graph data 
    y1: y1
    x1: x1
    x2: x2     
```

이때 오른쪽 아래로만 이동해야 하므로 다음과 같이 `y2` 를 구할 수 있다.

```
y1 + x1 = y2 + x2
     y2 = y1 + x1 - x2
```

두명의 이동겨로에 대하여 다음과 같은 규칙을 발견할 수 있다.

```cpp
    r = max(max(dfs(C, G, y1+1, x1, x2),
                dfs(C, G, y1, x1+1, x2+1)),
            max(dfs(C, G, y1+1, x1, x2+1),
                dfs(C, G, y1, x1+1, x2)));
```

# Implementation

* [c++11](a.cpp)

# Complexity

````
O(N^3) O(N^3)
```
