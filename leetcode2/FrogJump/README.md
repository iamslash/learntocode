# Problem

[Frog Jump](https://leetcode.com/problems/frog-jump/)

# Idea

돌이 놓여있는 좌표의 모임 `S[]` 가 주어진다. 개구리가 `S[0]` 부터
점프를 한다. `S[i]` 에 도착하는데 `k` 만큼 점프했다면 `S[i]` 에서
`k-1, k, k+1` 만큼 점프할 수 있다. 마지막 좌표까지 이동할 수 있는지
검증하는 문제이다.

예를 들어 `S = [0, 1, 3, 5, 6, 8, 12, 17]` 의 경우를 살펴보자.

```
S: 0 1 3 5 6 8 12 17
   . 1
     . 2
       . 2
         . 3
             .  4
                .  5
                   .
ans: true
```

`Map<Integer, Set<Integer>> C` 를 선언하여 `C[p]` 에 `p` 좌표에
도착하는데 사용된 점프횟수를 저장한다. `S` 를 처음부터 끝까지
순회하면서 `C` 를 채우면 마지막에 `C[S[n-1]].size() > 0` 이면 `S[n-1]`
에 도착하는 방법이 있다는 의미이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N^2) O(N)
```
