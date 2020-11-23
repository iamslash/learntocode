# Problem

[Android Unlock Patterns](https://leetcode.com/problems/android-unlock-patterns/)

숫자 `m, n` 이 주어진다. 핸드폰의 9 개 키패드를 이어서 unlock pattern
을 만들어 보자. 이때 이어지는 키패드의 개수가 최소 `m` 개에서 `n` 개일
때 그 가짓수를 구하라.

# Idea

키패드가 다음과 같이 주어진다.

```
1 2 3
4 5 6
7 8 9
```

이동 가능한 횟수가 충분하다면  다음과 같은 규칙들을 생각해 낼 수 있다.

* `2` 를 이미 방문했다면 `1,3`, `3,1` 이동이 가능하다.
* `4` 를 이미 방문했다면 `1,7`, `7,1` 이동이 가능하다.
* `6` 를 이미 방문했다면 `3,9`, `9,3` 이동이 가능하다.
* `8` 를 이미 방문했다면 `7,9`, `9,7` 이동이 가능하다.
* `5` 를 이미 방문했다면 `1,9`, `9,1`, `2,8`, `8,2`, `3,7`, `7,3`,
  `4,6`, `6,4` 이동이 가능하다.
* 나머지 경우는 조건없이 이동이 가능하다. 예를 들어 `1,8`,`8,1` 은
  인접하지 않지만 이동이 가능하다.

`vector<vector<int>> bridge(10, vector<int>(10))` 를 선언하여
`bridge[i][j]` 에 `i` 에서 `j` 로 이동하기 위해 이미 방문했는지
알아볼 키패드의 번호를 저장한다.

```
bridge[1][3] = bridge[3][1] = 2
bridge[1][7] = bridge[7][1] = 4
bridge[3][9] = bridge[9][3] = 6
bridge[7][9] = bridge[9][7] = 8
bridge[1][9] = bridge[9][1] =
bridge[2][8] = bridge[8][2] =
bridge[3][7] = bridge[7][3] =
bridge[4][6] = bridge[6][4] = 5
```

이제 키패드에서 한개의 숫자가 정하면 이동할 수 있는 가짓수를 구할 수
있는 준비가 되었다.

다음과 같은 부분문제 `dfs` 를 선언하고 back tracking 으로 구현한다.

```cpp
int dfs(seen, bridge, u, remain)

return: counts of pattern for u
  seen: us is visited ?
     u: the node to visit
remain: remained count
```

`C[][]` 를 선언하여 최적화 할 수 있다. 이때 seen 은 bit sequence 로 저장해야 한다. `C[seen][u]` 에 `dfs(seen, bridge, u, remain)` 을 저장한다. 

# Implementation

* [c++11](a.cpp)
* [js](a.js)

# Complexity

```
O(N!) O(N)
```
