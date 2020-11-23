# Problem

[Largest 1-Bordered Square](https://leetcode.com/problems/largest-1-bordered-square/)

# Idea

그리드의 정보 `G[][]` 가 주어진다. 경계가 모두 1 인 가장 큰 정사각형을
찾아내고 그 정사각형안에 존재하는 점의 개수를 구하는 문제이다.

예를 들어 다음과 같이 `G[][]` 가 주어진다. `vector<vector<int>> H` 를
선언하고 왼쪽으로 부터 연속된 1 의 개수를 저장하고 `vector<vector<int>> V` 를
선언하고 위쪽으로 부터 연속된 1 의 개수를 저장한다.

```
G[][]          H[][]          V[][]

1 0 1 1 1 1    1 0 1 2 3 4    1 0 1 1 1 1 
1 0 1 1 0 1    1 0 1 2 0 1    2 0 2 2 0 2
1 1 1 0 0 1    1 2 3 0 0 1    3 1 3 0 0 3
0 1 1 1 1 1    0 1 2 3 4 5    0 2 4 1 1 4
1 1 1 0 1 0    1 2 3 0 1 0    1 3 5 0 2 0
1 0 1 0 0 0    0 0 1 0 0 0    0 0 6 0 0 0
```

`int ans` 를 선언하여 최대 길이를 저장한다.
그리고 `G[n-1][n-1]` 부터 `G[0][0]` 까지 순회하면서 다음을
반복한다.

* `int len` 을 선언하여 `min(V[y][x], H[y][x])` 를 저장하자.
* `len > ans` 동안 다음을 반복한다.
  * `V[y][x-len+1] >= len && H[y-len+1][x] >= len` 이면
    border 가 1 인 정사각형을 찾았다는 의미이다. `ans = len` 을 수행한다.

위의 예에서 `y == 4, x == 5` 인 경우를 살펴보자. 
`min(V[y][x], H[y][x] == 4` 
이므로 `len == 4` 이다. `V[y][x-len+1] == V[4][2] == 4` 이고
`H[y-len+1][x] == H[0][5] == 4` 이므로 `ans = 4` 를 수행한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(HW)
```
