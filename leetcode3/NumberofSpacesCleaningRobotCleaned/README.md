# Problem

[Number of Spaces Cleaning Robot Cleaned](https://leetcode.com/problems/number-of-spaces-cleaning-robot-cleaned/)

이차원 배열 `room[][]` 가 주어진다. `room[][]` 은 `0, 1` 로 구성되어
있다.  `0` 은 빈 공간이다. `1` 은 벽이 세워져있다. 로봇 청소기가
`(0,0)` 에서 오른쪽으로 바라 보고 있다. 바라보고 있는 다음 cell 이 벽
혹은 모서리이면 시계방향으로 90 도를 회전한다. 그리고 이동할 수 있는
cell 을 발견하면 이동한다.

로봇 청소시가 청소할 수 있는 cell 의 개수를 구하라.

# Idea

예를 들어 `room = [[0,0,0],[1,1,0],[0,0,0]]` 의 경우를 살펴보자.

```
0 0 0
1 1 0
0 0 0

0,0 0,1 0,2 90 1,2 2,2 90 2,1 2,0
```

따라서 답은 7 이다.


```
0 0 0
0 0 0
0 0 0

0,0 0,1 0,2 90 1,2 2,2 90 2,1 2,0 1,0
```

마지막 `1,0` 에서 다음 cell 이 벽 혹은 모서리가 아니다. 그러므로
첨소를 중단한다. 따라서 답은 8 이다. 답이 9 가 아님을 유의하자.

Java 로 구현할 때 다음과 같은 사항에 유의해야 한다.

```java
        Set<int[]> aSet = new HashSet();
        Set<List<Integer>> bSet = new HashSet();
        aSet.add(new int[]{1, 2, 3});
        System.out.println(aSet.add(new int[]{1, 2, 3})); // true
        bSet.add(List.of(1, 2, 3));
        System.out.println(bSet.add(List.of(1, 2, 3)));   // false
```

`Set<int[]>` 에 같은 `int[]` 가 삽입이 된다. `Set<List<Integer>>` 는
같은 `List<Integer>` 가 삽입되지 못한다. 따라서 `Set<int[]>` 대신
`Set<List<Integer>>` 를 사용해야 한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
