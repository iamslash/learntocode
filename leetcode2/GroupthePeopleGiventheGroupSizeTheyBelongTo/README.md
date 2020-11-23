# Problem

[Group the People Given the Group Size They Belong To](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/)

# Idea

n 명의 사람이 주어진다. 그리고 사람들이 포함되어야 할 group 별 크기
`G[]` 가 주어진다. 즉, `i` 가 속해야할 group 의 크기는 `G[i]` 와 같다.
모든 group 에 n 명의 사람을 그 크기에 맞게 배치한 결과를 구하는
문제이다.

`List<List<Integer>> ans` 를 선언하여 답을 저장한다.  `Map<Integer,
List<Integer>> groups` 를 선언하여 그룹의 크기별 사람들의 목록을
저장한다.  `groups.get(G[i])` 에 사람을 추가하고 그 크기가 `G[i]` 와
같다면 `ans` 에 추가하고 `groups.get(G[i])` 를 다시 비운다.

그룹의 크기가 가득찰 때까지 사람을 채우는 방법이므로 greedy algorithm
이라 할 만 하다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(N)
```
