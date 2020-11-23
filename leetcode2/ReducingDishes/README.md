# Problem

[Reducing Dishes](https://leetcode.com/problems/reducing-dishes/)

# Idea

수열 `S` 가 주어진다. `S[i]` 는 `i-dish` 의 만족도를 의미한다. 시간은
`time = [1, 2, 3,...]` 으로 표현한다. `Like-time-coefficient` 는
`S[i] * time[i]` 와 같다. `Like-time-coefficient` 가 최대가 되도록
`S[i]` 를 선택했을 때 그 최대 값을 구하는 문제이다.

예를 들어 `S = [-1, -8, 0, 5, -9]` 의 경우를 살펴보자.

시간이 적은 것은 낮은 `S[i]` 와 곱하고 시간이 많은 것은 높은 `S[i]` 와
곱해야 한다.

오름차순으로 정렬하면 `S = [-9, -8, -1, 0, 5]` 와 같다. 이제 어느 `S[i]`
부터 `time[i]` 를 곱할지 결정하면 된다.

```
S: -9 -8 -1 0 5
T:            1 : 5
            1 2 : 10
          1 2 3 : 14
       1  2 3 4 : 13
    1  2  3 4 5 : 7
```

따라서 답은 14 이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N^2) O(1)
```
