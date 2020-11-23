# Problem

[Check If Array Pairs Are Divisible by k](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/)

수열 `A[]` 와 숫자 `k` 가 주어진다. `A[]` 에서 두개씩 짝지어서 그 합이
`k` 로 나누어떨어지도록 해보자. 모든 수가 짝을 이루면 참이고 그렇지
않으면 거짓을 리턴하도록 하라.

# Idea

`var cntMap map[int]int` 를 선언하여 `k` 의 나머지를 key 로 하는 맵을
제작한다.

`A[i] % k < 0` 일 때는 `A[i] % k + k` 를 수행해야 한다. 따라서 key 는
`(A[i] % k + k) % k` 로 구한다.

`cntMap` 를 모두 채우면 `cntMap[0]` 를 살펴본다. 즉, k 로 나누엇을 때
나머지가 0 인 숫자들은 항상 짝수 이어야 한다. 그렇지 않으면 모두 짝을
이룰 수가 없다.

또한 인덱스 `i` 에 대해 `cntMap[i] == cntMap[k-i]` 이어야 한다. 그렇지
않으면 모두 짝을 이룰 수가 없다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(N)
```
