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
대부분 bitmask 를 이용하여 해결 할 수 있다. 각 문자를 다음과 같은 
bitmask 로 표현할 수 있다.

```
 a: 0001
 b: 0010
 c: 0100
 d: 1000
ab: 0011
cd: 1100
```

어떤 문자열 `s = "abcabc"` 가 있다고 해보자. 이번에 따져봐야할 문자가
"abcabc" 라고 하자. "abc" 가 두번 반복되기 때문에 "abcabc" 는
Wonderful String 이다. 임의의 문자열이 두번 반복되었다면 모든 문자가
두번씩 반복되었기 때문에 Wonderful String 이 맞다.

`int[] cnts = new int[1024]` 를 선언하여 bitmask 의 발생숫자를
기록한다. 예를 들어 `cnts[0111]` 은 "abc" 의 발생횟수를 의미한다.
`cnts[0000] = 1` 로 초기화 한다. seed 값이다.

"abcabc" 의 substring 중 "abcabc" 를 살펴보자. "abcabc" 의 bitmask 는
`0000` 이다. `cnts[0000] == 1` 이므로 답에 1 를 더한다.

"abcabcabcabc" 의 substring 중 "abcabcabcabc" 를
살펴보자. "abcabcabcabc" 의 bitmask 는 `0000` 이다. `cnts[0000] == 2`
이므로 답에 2 를 더한다.

"abcabc" 의 substring 중 "abca" 를 살펴보자. "abca" 의 bitmask 는
`0001` 이다. 예전에 어떤 substring 인지는 모르겠지만 임의의 문자
한개가 없거나 있는 문자열에서 "abca" 가 되었다고 해보자. 즉, 임의의
문자 한개를 XOR 한 문자열에서 "abca" 가 되었다고 해보자. 그 임의의
문자열를 `prev` 이라고 하자.  `cnts[prev] > 0` 이라면 그것을 답에 더해야
한다.

`word` 는 `[a..j]` 로만 구성된다. `[a..j]` 중 하나만 있거나 없었던
문자열 `prev` 는 다음과 같이 만들어낼 수 있다.

```
curr: 0001
prev: 0001 ^ 0001 = 0000
      0001 ^ 0010 = 0011
      0001 ^ 0100 = 0101
      0001 ^ 1000 = 1001
      ...
      0001 ^ 1000000000 = 1000000001
```

다음은 "aa" 의 풀이과정이다.

```
               i
word:     a    a    
  bm:  0001 0000
               j
               a    b   ba     dcba      jihgfedcba
cnts:  0000 0001 0010 0011 ... 1111 .... 1111111111
          1    1    0    0        0               0
 ans:     3
```

다음은 "aba" 의 풀이과정이다.

```       
               i
word:     a    b    a
  bm:  0001 0011 0010
               j
               a    b   ba     dcba      jihgfedcba
cnts:  0000 0001 0010 0011 ... 1111 .... 1111111111
          1    1    0    1        0               0
 ans:     2
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
