# Problem

[https://leetcode.com/problems/unique-paths/](https://leetcode.com/problems/unique-paths/)

숫자 `h, w` 가 주어진다. 높이와 넓이가 각각 `h, w` 인 보드를 `G[][]` 라고 하자. `G[0][0]` 에서 출발하여 `G[h-1][w-1]` 까지 오른쪽 혹은 아내쪽으로 이동할 수 있다. 모든 경로의 수를 구하라.

# Recursive Dynamic Programming

## Idea

```
             dfs(0,0)
            /        \
     dfs(1,0)         dfs(0,1)
     /     \           /     \
dfs(2,0) dfs(1,1) dfs(1,1) dfs(0,2)
```

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(HW) O(HW)
```

# Iterative Dynamic Programming

## Idea

`int[][] C = new int[h][w]` 를 선언한다. 다음과 같은 dynamic equation 을 발견할 수 있다.

```
C[y][x] = C[y-1][x] + C[y][x-1]
```

`int[] C = new int[w]` 를 선언하여 공간복잡도를 더욱 개선할 수 있다.

```
C[x] += C[x-1]
```

## Implementation

* [c++11](a.cpp)
* [java17](MainApp.java)
* [py3](a.py)
* [go](a.go)
* [js](a.js)
* [ruby](a.rb)

## complexity

```
O(HW) O(W)
```

# Math

## Idea

오른쪽으로 이동하는 것을 `1` 이라 하고 아래쪽으로 이동하는 것을 `0` 이라고 하자.  예를 들어 `h = 3, w = 2` 는 다음과 같이 표시할 수 있다.

```
101
001
010
```

`h-1` 개의 `1` 과 `w-1` 개의 `0` 의 조합과 같다. 따라서 다음과 같은 math equation 을 발견할 수 있다.

```c
ans = (h + w - 2)! / (h-1)! * (w-1)!
```

## Implementation

* [py3](math.py)

## complexity

```
O(N) O(1)
```
