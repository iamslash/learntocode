# Problem

[Number of Wonderful Substrings](https://leetcode.com/problems/number-of-wonderful-substrings/)

문자열 `word` 가 주어진다. `word` 의 문자는 `[a..j]` 중 하나이다.

다음과 같은 규칙을 지키는 문자열을 wonderful string 이라고 하자.

* 같은 문자의 개수가 홀 수인 것은 최대 한개이다.

예를 들어 `ccjjc` 는 `c` 만 홀수개 이므로 wonderful string 이다. 또한
`abab` 는 홀수개인 문자가 없으므로 wonderful string 이다. 그러나 `ab`
는 홀수개인 문자가 `a`, `b` 이므로 wonderful string 이 아니다.

`word` 의 substring 중 wonderful string 인 것들의 개수를 구하라.

# Idea

예를 들어 `word = "aba"` 의 경우를 살펴보자.

```
 _
"aba" -> "a"
  _
"aba" -> "b"
   _
"aba" -> "a"
 ___
"aba" -> "aba"
```

따라서 답은 4 이다.

`word[i]` 의 후보는 `[a..j]` 와 같이 10 개 뿐이다. 이런 문제는
대부분 bitmask 를 이용하여 해결 할 수 있다.

어떤 문자열 `s` 가 있다고 해보자. 그리고 `s` 의 wonderful string
의 개수를 알고 있다고 해보자. 그 개수를 `wonderfulCnt` 라고 하자.
새로운 문자 `c` 가 하나 추가되었을 때 `wonderfulCnt` 를 어떻게
계산할 수 있는지 생각해 보자. 

`s` 를 bitmask 로 표현헤 보자. 예를 들어 `s = ab` 이라면 bitmask 는
`11` 이다. `s = aba` 라면 bitmask 는 `10` 이다. 

```
        i
word:   a b a b c c b
  bm:   1 3 2 0 4 0 2
cnts: 0 
      1
 ans:   0
```

too difficult

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
