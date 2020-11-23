# Problem

[Two City Scheduling](https://leetcode.com/problems/two-city-scheduling/)

# Idea

사람마다 `A` 도시및 `B` 도시에 도착했을 때의 비용의 모임 `C[][]` 가
주어진다.  즉, `C[i][0]` 은 `i` 사람이 `A` 도시에 가는 비용이다.
`C[i][1]` 은 `i` 사람이 `B` 도시에 가는 비용이다.

`2N` 의 사람이 있다고 해보자. `N` 의 사람은 `A` 로 가고 `N` 의 사람은
`B` 로 가야할 때 전체 비용이 최소가 되도록 해보자. 그 비용을 구하는
문제이다.

`C` 를 `C[i][1] - C[i][0]` 의 내림차순으로 정렬한다. 이제 `[0..N-1]` 의 사람은
`A` 로 보내고 `[N..2N-1]` 의 사람은 `B` 로 보내자.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(NlgN) O(1)
```
