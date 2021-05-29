# Problem

[Verifying an Alien Dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/)

문자열의 모음 `words[]`, 문자열 `order` 가 주어진다. 임의의 문자열
`words[i]` 에 대해 알파벳의 사전순서는 `order` 로 한다. `words[]`
가 사전순으로 정렬되어 있는지 검증하라.

# Idea

예를 들어 `words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"`
의 경우를 살펴보자.

```
i
hello
leetcode
```

`order` 를 적용한 사전순서를 생각해 보자. `h < l` 이므로 답은 `true` 이다.

`words[i-1]` 과 `words[i]` 의 문자열을 하나씩 비교하여 사전순서인지
조사한다.  이때 첫번째로 서로 다른 문자가 발견되었을 때를 인덱스 `j`
라고 하자. 두 문자열이 정렬되었는지는 `words[i-1][j] < words[i][j]` 만
검증하면 된다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
