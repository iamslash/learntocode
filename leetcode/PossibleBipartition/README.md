# Problem

[Possible Bipartition](https://leetcode.com/problems/possible-bipartition/)

# Idea

사람들의 숫자 `N` 과 싫어하는 관계의 모음 `D[][]` 가 주어진다.
사람들을 서로 싫어하지 않는 두 그룹으로 반드시 구분할 수 있는지
검증하는 문제이다.

한 사람을 `u` 라고 하자. `u` 가 `0` 그룹이면 `u` 가 싫어하는 사람은
`1` 그룹이어야 한다. 모든 사람들을 순회하면서 사람마다 그룹을 정하고
서로 같은 그룹에 속하는 경우가 발견되면 실패로 처리한다.

전형적인 dfs color 문제이다.

다음과 같은 부분문제 `dfs` 를 정의한다.

```cpp
bool dfs(int u, int c)
     u: 이번에 방문하는 사람
     c: u 가 속할 그룹번호
return: u 가 c 그룹에 속하는가?
```

특정 사람에 대한 그룹정보는 `vector<int> m_color` 에 저장한다.
싫어하는 관계는 `unordered_map<int, vector<int>> m_adj` 에 저장한다.

그리고 `dfs` 를 반복해서 호출할 `dfsAll` 의 loop 를 다음과 같이 구현한다.

```cpp
for (int u = 1; u <= N; ++u) {
  if (m_color[u] == -1)
    continue;
  if (!dfs(u, 0))
    return false;
}
```

`dfs` 는 다음과 같이 구현한다.

* `m_color[u] == c` 이면 `u` 는 `c` 그룹에 이미 속해있다는 의미이다. `return true` 를 수행한다.
* `m_color[u] != -1` 이면 `u` 는 이미 방문했는데 `c` 그룹이 아니라는 의미이다. `return false` 를 수행한다.
* `m_color[u] = c` 한다. 그리고 `dfs loop` 를 수행한다.
  * `u` 의 이웃들 `v` 를 방문한다. `dfs(v, c ^ 1) == false` 이면 `return false` 를 수행한다.
* `dfs loop` 가 종료하면 `return true` 한다.

# Implementation

* [c++11](a.cpp)

# Complextiy

```
O(V+E) O(VE)
```