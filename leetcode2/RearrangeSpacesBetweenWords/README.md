# Problem

[Rearrange Spaces Between Words](https://leetcode.com/problems/rearrange-spaces-between-words/)

문자열 `s` 가 주어진다. 공백 문자들을 각 문자열 사이에 동일하게
배치하라.  남는 공백문자는 끝에 추가한다.

# Idea

예를 들어 `s = "  this   is  a sentence "` 를 살펴보자. 

```
  cntSpace : 9
   cntWord : 4
unitSpace  : 9 / (4-3) = 3
  tailSpace: 0
```

따라서 답은 `"this   is   a   sentence"` 이다.

java 의 `split, repeat` 과 같은 API 가 있다면 쉽게 구현할 수 있다.

`split` 함수는 하나 이상의 공백을 구분자로 동작해야 하므로 regex 를
지원해야 한다. 예를 들어 `split(s, "\\s+)"` 와 같이 사용한다.

`repeat` 함수는 단일 문자를 반복하여 문자열을 만들 수 있어야 한다. 예를 들어
`"".repeat(3, "")` 와 같이 사용한다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(N)
```
