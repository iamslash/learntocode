# Problem

[Minimum Number of Moves to Make Palindrome](https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/)

문자열 `s` 가 주어진다. 인접한 문자끼리 얼마든지 교환할 수 있다.
최소로 교환해서 `s` 를 palindrome 으로 만들어보자.  그 최소 교환횟수를
구하라.

# Idea

예를 들어 `s = "aabb"` 를 살펴보자.

```
s: a a b b
   a b a b
   b a a b
```

따라서 답은 `2` 이다.

문제의 조건에 의해 `s` 는 반드시 palindrome 으로 만들 수 있다.

greedy algorithm 을 이용해서 해결할 만 하다.  먼저 `s[n-1]` 과 같은
문자를 찾는다. 그것을 `s[0]` 으로 옮긴다. 이 때 이동거리를 답에
더한다. 그리고 `s[0], s[n-1]` 를 제거한다. 문자가 비워질 때까지
반복한다.

```
         i  
  s: a a b b
     b a a b    2
     a a
   
ans: 2
```

이때 `s = "aaaac"` 인 경우를 살펴보자. 문자가 한개인 경우는 특별히
처리를 해야 한다. `c` 는 `s[n/2]` 로 옮겨야 함을 주의하자.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(1)
```
