# Problem

[Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/)

문자열 `s, locked` 가 주어진다. `s` 는 `(, )` 로만 구성된다.
`locked` 는 `0, 1` 로만 구성된다. 그리고 다음과 같은 규칙이 있다.

* `locked[i] == 0` 이면 `s[i]` 를 `(` 혹은 `)` 로 바꿀 수 있다.
* `locked[i] == 1` 이면 `s[i]` 를 바꿀 수 없다.

`s` 는 과연 valid 하게 바꿀 수 있는가를 검증하라.

# Idea

예를 들어 `s = "))()))", locked = "010100"` 를 살펴보자.

```
locked: 010100
     s: ))()))
        *)*)**
        
        ()()()
```

따라서 답은 `true` 이다.

`locked[i] == 0` 이면 `s[i] == *` 라고 해보자. 다음과 같은
몇가지 경우를 생각해 보자.

```
s: **))
   *)*)
   ))**
   )*)*
```

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
