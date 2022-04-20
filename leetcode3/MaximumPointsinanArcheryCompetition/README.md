# Problem

[Maximum Points in an Archery Competition](https://leetcode.com/problems/maximum-points-in-an-archery-competition/)

숫자 `numArrows`, 수열 `aliceArrows[]` 가 주어진다.  alice 와 bob 이
서로 궁수대회를 한다. 각각 `numArrows` 만큼 화살을 사용할 수
있다. `aliceArrows.length == 12` 이다.

점수를 획득하는 규칙은 다음과 같다.

* `aliceArrows[i] > bobArrows[i]` 이면 alice 가 `i` 만큼 점수를 갖는다.
* `aliceArrows[i] < bobArrows[i]` 이면 bob 이 `i` 만큼 점수를 갖는다.
* `aliceArrows[i] == bobArrows[i]` 이면 누구도 점수를 갖지 못한다.

bob 이 최대 점수를 획득하도록 `bobArrows[]` 를 구하라.

# Idea

다음과 같은 변수를 멤버로 선언한다.

* `int maxBobPoint` 를 선언하여 bob 의 최고점수를 저장한다.
* `int[] maxBobArrows` 를 선언하여 bob 이 최고점수를 획득했을 때
  점수별로 사용한 화살의 개수를 저장한다.
  
앞서 선언한 두 변수는 [backtracking]() 의 Best 에 해당한다.

다음과 같은 부분문제 `dfs()` 를 선언한다.

```
void dfs(aliceArrows, bobArrows, bobPoint, remained, pos)

aliceArrows: input
  bobArrows: bob 이 사용한 점수별 화살의 개수
   bobPoint: bob 이 현재 획득한 점수
   remained: bob 에게 남아있는 화살의 개수
        pos: 이번에 따져볼 bobArrows 의 인덱스. 곧, 점수이다.
```

`bobArrows, bobPoint` 는 [backtracking]() 의 Candidate 에 해당한다.

`dfs()` 의 `base` 는 다음과 같이 구현한다.

* `pos < 0 || remained <= 0` 이면
  * `remained > 0` 이면 남은 화살을 점수 0 에 사용하자. 즉,
    `bobArows[0] += remained` 를 수행한다.
  * `bobPoint > maxBobPoint` 이면 
    * Candidate 를 Best 에 assign 하자. 즉, `maxBobPoint = bobPoint,
      maxBobArrows = bobArros.clone()` 을 수행한다.
  * return 한다.

`dfs()` 의 `recursion` 는 다음과 같이 구현한다.

* bob 이 점수 pos 를 획득하는 경우를 탐색한다. 즉, `aliceArrows[pos] +
  1` 개의 화살을 사용하여 점수 pos 를 획득한 경우를 따져보기 위해
  `dfs()` 를 호출한다. `dfs()` 를 호출하고 나서 사용했던 화살을 원래
  값으로 돌려 놓아야 한다. 즉, `bobArrows[pos] = 0` 을 수행한다.
* bob 이 점수 pos 를 획득하지 못한 경우를 탐색한다. `dfs()` 를
  호출하고 나서 사용했던 화살을 원래 값으로 돌려 놓아야 한다. 즉,
  `bobArrows[pos] = 0` 을 수행한다. 

모든 순회를 마치면 `maxBobArrows` 가 곧 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(2^N) O(N)
```
