# Problem

[Can You Eat Your Favorite Candy on Your Favorite Day?](https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/)

수열 `candiesCount[]`, 질의 `queries[][]` 가
주어진다. `candiesCount[i]` 는 `i-th type` 캔디의 개수이다.
`queries[i]` 는 `[favoriteType-i, favoriteDay-i, dailyCap-i]` 로
구성된다. 하루에 최대 `dailyCap-i` 만큼 캔디를 먹을 수 있다.
`favoriteDay-i` 날에 `favoriateType-i` 타입의 캔디를 먹을 수 있는가를
의미한다.

캔디를 먹는 규칙은 다음과 같다.

* 0 번째 날부터 먹는다.
* `i-1` 타입의 캔디를 모두 먹어야 `i` 타입의 캔디를 먹을 수 있다.
* 하루에 최소 하나의 캔디는 먹어야 한다.

`ans[]` 는 답의 모음을 의미한다. `ans[i]` 에 `queries[i]` 의 답을
저장하라.

# Idea

예를 들어 `candiesCount = [7,4,5,3,8], queries =
[[0,2,2],[4,2,4],[2,13,1000000000]]` 의 경우를 살펴보자.

```
candiesCount: 7 4 5 3 8
     queries: 0 2 2
              4 2 4
              2 13 1000000000

         day: 0 . . . . 5 . . . . 10 . . 13
  queries[0]: 2 2 
  queries[1]: 
  queries[2]: 1 1 1 1 1 1 1 1 1 1  1 1 1 
```

`queries[0] = [0,2,2]` 의 경우를 살펴보자. 하루에 최대 `2`
개까지 먹을 수 있다. `0` 타입의 캔디를 `2` 번째 날에 먹을
수 있는지 따져보자. 날짜 순서대로 `2, 2` 만큼 먹으면 `2` 번째 날에
`0` 번 타입의 캔디를 먹을 수 있다.

`ps[]` 를 선언하여 `candiesCount[]` 의 부분합을 저장한다. 즉, 
`ps[3]` 은 `3` 타입 캔디까지의 합을 의미한다.

`queries[i] == [type, day, cap]` 이라고 해보자. `day` 동안
`cap` 개씩 먹은 캔디의 수를 `mostCnt` 라고 하자. `day` 동안
`1` 개씩 먹은 캔디의 수를 `leastCnt` 라고 하자.

`mostCnt = (day + 1) * cap` 이다. `leastCnt = (day + 1) * 1` 이다.

`ps[type - 1] < mostCnt` 이고 `ps[type] >= leastCnt` 이면 `ans[i]`
는 `true` 이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(1)
```
