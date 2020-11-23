# Problem

[Shortest Path to Get All Keys](https://leetcode.com/problems/shortest-path-to-get-all-keys/)

이차원 배열 `G[][]` 가 주어진다. `G[y][x]` 는 `#, @, .` 와 `[a-fA-F]` 로
구성된다. 

* `@` 출발 지점이다.
* `.` 은 땅이다. 갈 수 있다.
* `#` 은 벽이다. 갈 수 없다.
* `[a-f]` 는 열쇠이다. 지나갈 때 마다 획득한다. 
* `[A-F]` 는 문이다. 획득한 소문자 열쇠로 열 수 있다. 단 같은
  문자이어야 한다.

`a <= key <= f` 일 때 열쇠는 `a <= key` 만큼 배치된다.

주어진 열쇠를 모두 획득하기 위해 필요한 최소 경로를 찾아라.


# Idea

가중치가 1 인 최소 경로 문제이다. BFS 로 해결할 만 하다.

`class State` 를 선언하여 `y, x, keys` 를 저장한다.

`Queue<State> q = new LinkedList<>();` 를 선언하여 BFS queue 로
이용한다.

`Set<String> visit = new HashSet<>();` 를 선언하여 방문한 곳을
저장한다.  이때 `keys + ',' + y + ',' + x` 를 `visit` 에 저장한다.

`int sy, sx` 를 선언하여 시작점을 저장한다. `int endKeys` 를 선언하여
배치된 열쇠들을 bit sequence 로 저장한다. 이제 `G[][]` 를 순환하면서
`sy, sx, endKeys` 를 채운다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(HW) O(HW)
```
