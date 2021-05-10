# Problem

> [Splitting a String Into Descending Consecutive Values](https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/)

숫자로 구성된 문자열 `s` 가 주어진다. `s` 를 다음의 조건을 만족시킬 수
있는지 검증하라.

* `s` 를 2 개 이상의 부분문자열로 나눈다.
* 나누어진 부분문자열은 내림차순이다.

# Idea

예를 들어 `s = "050043"` 의 경우를 살펴보자.

```
s: 050043
s: 05 004 3
```

따라서 답은 true 이다.

[back tracking](/doc/backtracking.md) 으로 해결할 만 하다.

다음과 같은 부분문제 `dfs` 를 정의한다.

```
boolean dfs(String s, long prev)

return: s is decrasing substrings?
     s: string which is consisted of digits
  prev: previous number
```

`long curr = 0` 을 선언하여 현재 추출한 숫자를 저장한다. `int n = s.length()` 를 선언하여 `s` 의 길이를 저장한다.

인덱스 `i` 를 이용하여 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `curr` 에 현재 숫자를 추출한다. 즉, `curr = curr * 10 + s.charAt(i) - '0'` 를 저장한다.
* `curr >= 10_000_000_000L` 이면 문제의 조건에 어긋난다. `false` 를 리턴한다.
* `prev < 0` 이면 첫번째 호출이다. 
  * curr 를 이전숫자로 해서 다음 부분문자열을 찾는다. 즉, `dfs(s.substring(i+1), curr` 이면 `true` 를 리턴한다.
  * 건너뛴다.
* `curr == prev - 1` 이면 현재 숫자는 이전 숫자보다 하나 작다. 
  * `i == n - 1` 이면 현재 숫자는 마지막 부분문자열이다. `true` 를 리턴한다.
  * curr 를 이전숫자로 해서 다음 부분문자열을 찾는다. 즉, `dfs(s.substring(i+1), curr` 이면 `true` 를 리턴한다.

모든 반복을 마치면 `false` 를 리턴한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(2^N) O(N)
```
