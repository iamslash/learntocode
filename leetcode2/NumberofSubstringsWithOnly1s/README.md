# Problem

[Number of Substrings With Only 1s](https://leetcode.com/problems/number-of-substrings-with-only-1s/)

`0, 1` 로만 구성된 문자열 `s` 가 주어진다. 연속된 `1` 의 부분집합의
수를 모두 구하라. 결과값은 `10^9 + 7` 으로 modulo 연산을 구행한다.

# Idea

예를 들어 `111` 의 경우 부분집합의 개수는 `3(3+1)/2 = 6` 이다.  이것은
`111` 를 인덱스 `i` 를 사용하여 처음부터 끝까지 순회하면서 `1` 의
개수를 누적하여 더한 것과 같다.

```
     i          i          i
  A: 1 1 1    1 1 1    1 1 1
ans: 1        3        6
```

`cnt := 0` 을 선언하여 연속된 `1` 개수를 저장한다.  `A` 를 인덱스 `i`
를 사용하여 처음부터 끝까지 순회하면서 `ans` 에 `cnt` 를 더한다. 모든
반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
