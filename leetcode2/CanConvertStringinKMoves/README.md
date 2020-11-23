# Problem

[Can Convert String in K Moves](https://leetcode.com/problems/can-convert-string-in-k-moves/)

두개의 문자열 `s, t`, 숫자 `k` 가 주어진다.  임의의 `i` 에 대해 `s[i]`
를 회전하여 `t[i]` 를 만들 수 있다. 이때 회전한 숫자가 이전에 한번
사용되었으면 회전한 수에 26 을 더해야 한다. 만약 두번 사용됬으면 26 *
2 를 더해야 한다. `s` 가 `t` 와 같도록 하려면 얼만큼 회전해야 하는지
구하라. 그 수가 `k` 보다 작거나 같다면 `true` 를 리턴하고 그렇지
않으면 `false` 를 리턴하라.

# Idea

예를 들어, `s = "input", t = "ouput", k = 9` 의 경우를 살펴보자.

```
t : o u p u t
s : i n p u t
    j o
    k p
    l q
    m r
    n s
    o t
      u
ans: true      
```

이번에는 `s = "abc", t = "bcd", k = 10` 의 경우를 살펴보자.

```
t: b c d
s: a b c
   b c d
     d e
     . .
     . .
     . .
     c d
       e
       .
       .
       .
       d
ans: false  
```

일단 `len(s) != len(t)` 이면 false 를 리턴한다.

회전한 수는 `diff = int(t[i]) - int(s[i])` 를 이용해 구할 수 있다.  이때
음수가 되는 것을 막기 위해 26 을 더하고 26 을 modulo 연산 한다.

`cnts := make([]int, 26)` 를 선언하여 회전한 단위 수를 `cnts[diff]` 에
저장한다. 진짜 회전한 수는 `diff + cnts[diff] * 26` 으로 구한다.

만약 진짜 회전한 수가 `k` 보다 크면 false 를 리턴한다.

모든 반복을 마치면 true 를 리턴한다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
