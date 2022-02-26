# Problem

[Unique Substrings With Equal Digit Frequency](https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/)

문자열 `s` 가 주어진다. `s` 는 숫자로만 구성되어 있다. `s` 의
substring 들중 문자열을 구성하는 숫자의 개수가 동일한 것들의 개수를
구하라.

# Idea

예를 들어 `s = "1212"` 의 경우를 살펴보자.

```
s: 1212
   1
   12
   1212
    2
    21
```

따라서 답은 `5` 이다.

다음과 같이 2 개의 loop 를 구상한다.

```java
for (int i = 0; i < n; ++i) {
  for (int j = i; j < n; ++j) {
  }
}
```

`i` 부터 `j` 까지의 substring 마다 구성하는 숫자의 개수가 같은지 검사한다.
그렇다면 `Set<String> strSet` 에 추가한다. 모든 반복을 마치면 `strSet.size()` 가
답이다.

`Set<String> strSet` 대신 `Set<Integer> numSet` 을 선언하여 `String` 대신 hash
에 해당하는 `Integer` 를 삽입해 보자. 이것을 [rolling
hash](/fundamentals/hash/rollinghash/README.md) 라고 한다. hash set 의 time,
space complexity 를 최적화할 수 있다. 

또한 `Set<Integer> numSet` 대신 trie 를 사용해보자. 지금까지 발견한 substring
들을 trie 에 저장해 놓으면 마찬가지로 `Set<String> strSet` 을 사용한 방법보다
time, space complexity 를 최적화할 수 있다.

# Implementation

* [java8](MainApp)

# Complexity

```
O(N^2) O(N)
```
