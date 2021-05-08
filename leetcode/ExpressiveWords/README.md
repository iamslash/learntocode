# Problem

> [Expressive Words](https://leetcode.com/problems/expressive-words/)

문자열 `s`, 문자열의 모음 `words[]` 가 주어진다. `words[]` 의 문자열들
중 다음과 같은 오퍼레이션을 수행하여 `s` 와 같아질 수 있는 것의 개수를
구하라.

* `words[i]` 의 한문자 `c` 를 2 개 이상 연속으로 추가할 수 있다. 예를
  들어 `s = "heeello"` 이고 `words[i] = hello` 라고 하자. `hello` 의
  `e` 를 2 개 추가하면 `heeello` 를 만들 수 있다.

# Idea

예를 들어 `s = "heeellooo", words = ["hello", "hi", "helo"]` 의 경우를
살펴보자. 

```
    s: heeellooo
words: he  llo
words: hi
words: he  lo
```

따라서 답은 `1` 이다.

four pointer 로 해결할 만 하다. `int i1, i2, j1, j2` 를 선언하고 `s`
의 시작과 끝, `words[i]` 의 시작과 끝을 저장한다.

만약 `s[i1]` 부터 `s[i2]` 까지 같은 문자이고 `words[i][j1]` 부터 `wo
rds[i][j2]` 까지 같은 문자라고 해보자. 만약 다음이 성립하면 `s` 는
`words[i]` 의 stretchy 가 될 수 있다.

```
length of s[i1..i2] - length of words[j1..j2] >= 2
```

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
