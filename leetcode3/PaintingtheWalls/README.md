# Problem

[Painting the Walls](https://leetcode.com/problems/painting-the-walls/)

배열 `cost[], time[]` 가 주어진다. `n` 개의 벽울 칠해보자. 두명의
페인터가 있다.

첫번째 페인터는 `i` 번째 벽을 `cost[i]` 의 비용과 `time[i]` 의
시간으로 칠한다.

두번재 페인터는 어떤 벽이든 `0` 의 비용과 `1` 의 시간으로 하나의 벽을
칠한다. 단, 첫번째 페인터가 지불한 시간만큼만 일한다.

예를 들어 첫번째 페인터가 `i` 번째 벽을 `2` 의 비용으로 `2` 시간동안
칠했다면 두번째 페인터는 `0` 의 비용으로 `2` 시간동안 2 개의 벽을 칠할
수 있다는 말이다.

`n` 개의 벽을 최소의 비용으로 칠할 때 그 최소 비용을 구하라.

# Idea

예를 들어 `cost = [1,2,3,2], time = [1,2,3,2]` 의 경우를 살펴보자.

```
    cost: 1 2 3 2
    time: 1 2 3 2

painter1:     3
              3
painter2: 0 0   0
          1 1   1

painter1: 1 2
          1 2 
painter2:     0 0
              1 1 
```

따라서 답은 `3` 이다.

[0/1 knapsack](/fundamentals/dynamicprog/knapsack01/README.md) 과
비슷하다. iterative dynamic programming 으로 해결할 만 하다.

`int[] C = new int[n + 1]` 을 선언하여 `n` 개의 벽을 칠할 때 최소
비용을 저장하자. `C[0] = 0` 으로 초기화 하자.

다음과 같이 인덱스 `i, w` 를 선언하여 nested loop 로 구현하자.

```java
// i: wall index to be painted by painter-1
// w: remained count of walls to be painted
for (int i = 0; i < n; ++i) {
    for (int w = n; w > 0; --w) {
    }
}
```

다음과 같은 dynamic equation 을 만들어낼 수 있다.

```
C[w] = min(C[w], cost[i] + C[w - time[i] - 1])

           remained walls: w - time[i] - 1
painted walls by painter-1: 1
painted walls by painter-2: time[i]
```

예를 들어 `cost = [1,2,3,2], time = [1,2,3,2]` 의 풀이과정을 살펴보자.

```
cost: 1 2 3 2
time: 1 2 3 2 
   C: 0 M M M M

      i
cost: 1 2 3 2
time: 1 2 3 2
   C: 0 1 1 M M
   
C[2] == 1 은 벽이 2 개 남았을 때 painter-1 이 0-th 벽을 칠한다. 
최소비용이 1 이라는 말이다.

        i
cost: 1 2 3 2
time: 1 2 3 2
   C: 0 1 1 2 3

          i
cost: 1 2 3 2
time: 1 2 3 2
   C: 0 1 1 2 3

            i
cost: 1 2 3 2
time: 1 2 3 2 
   C: 0 1 1 2 3
```

따라서 답은 `3 (C[4] == 3)` 이다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N^2) O(N)
```
