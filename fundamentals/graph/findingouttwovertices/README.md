# Problem

그래프 `adj[][]` 와 두 정점 `u, v` 이 주어지면 두 정점이 한 그래프에 있는지 검증하는 문제이다.

# Idea

`dfs(u)` 를 수행한다. `visit[v] == true`  인지 확인한다.