# Problem

> [Maximum Number of Accepted Invitations](https://leetcode.com/problems/maximum-number-of-accepted-invitations/)

이차원 배열 `G[][]` 가 주어진다. `G[u][v]` 는 `u-th` 소년이 초대장을
보내면 `v-th` 소녀가 그것을 허락하는 것을 의미한다. 즉, `G[u][v] == 1`
이면 허락하는 것이고 `G[u][v] == 0` 이면 거절을 의미한다.

한명의 소년은 최대 1 명의 소녀를 초대할 수 있다. 한명의 소녀 역시 최대
1 명의 소년의 초대를 수락할 수 있다. 최대로 초대가 가능한 쌍의 개수를
구하라.

# Idea

[maximum bipartite matching](/fundamentals/graph/bipartitematching/README.md) 으로 해결할 만 하다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(|V||E|) O(|V|)
```
