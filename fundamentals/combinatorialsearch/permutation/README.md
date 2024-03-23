# Problem

양의 정수 `n` 을 입력받았을 때 `[1..n]` 의 숫자를 일렬로 배열하는 방법을 모두 찾는다.

# Idea

다음은 수열 `1 2 3` 의 순열을 찾는 과정의 recursion tree 이다.

```c
Idea: back tracking

nums: 1 2 3

dfs[1,2,3], 0)
  dfs[1,2,3], 1)
    dfs[1,2,3], 2)
    dfs[1,3,2], 2)
  dfs[2,1,3], 1)
    dfs[2,1,3], 2)
    dfs[2,3,1], 2)
  dfs[3,1,2], 1)
    dfs[3,1,2], 2)
    dfs[3,2,1], 2)
```

# Implementation

- [c++11](a.cpp)
- [java](MainApp.java)

# Complexity

```
O(N!) O(N)
```
