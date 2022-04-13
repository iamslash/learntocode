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
s: *)  -- true
   *(  -- false
   (*  -- true
   )*  -- false
```

`int wild, open, close` 를 선언하여 `*, (, )` 의 개수를
저장한다. 

이제 `s[], l[]` 를 `[0..n-1]` 동안 반복하며 다음을 반복한다.

* `l[i] == '0'` 이면 `wild++` 를 수행한다.
* `s[i] == '('` 이면 `open++` 를 수행한다.
* `s[i] == ')'` 이면 `close++` 를 수행한다.
* `wild + open - close < 0` 이면 `false` 를 리턴한다.

다음에는 `s[], l[]` 를 `[n-1, 0]` 동안 반복하며 다음을 반복한다.

* `l[i] == '0'` 이면 `wild++` 를 수행한다.
* `s[i] == '('` 이면 `open++` 를 수행한다.
* `s[i] == ')'` 이면 `close++` 를 수행한다.
* `wild + close - open < 0` 이면 `false` 를 리턴한다.

모든 반복을 마치면 `true` 를 리턴한다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
