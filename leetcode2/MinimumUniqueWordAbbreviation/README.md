# Problem

[Minimum Unique Word Abbreviation](https://leetcode.com/problems/minimum-unique-word-abbreviation/)

# Idea

특정 문자열 `T`, 문자열의 모음 `W[]` 가 주어진다. `T` 는 여러가지 abbreviation 을 갖는다.
abbreviation 은 문자와 숫자를 합하여 문자열의 문자개수를 줄여서 표현하는 방법이다.
예를 들면 `T = word` 일때 다음과 같은 abbreviation 이 가능하다.

```
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", 
"wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
```

`T` 의 abbreviation 이 `W[]` 의 abbreviation 들과 conflict 가 없고
그 길이가 최소인 것을 구하는 문제이다.

`List<String> abbs` 를 선언하고 `T` 의 abbreviation 들을 저장 및 정렬한다. [Generalized Abbreviation](/leetcode/GeneralizedAbbreviation/README.md)

`abbs` 를 순회하면서 다음을 반복한다.

* 다시 `W[]` 를 순회하면서 다음을 반복한다.
  * `abbs[i]` 와 `W[j]` 가 충돌하는지 검증한다. [Valid Word Abbreviation](/leetcode/ValidWordAbbreviation/a.cpp)
  * 만약 충돌한다면 `abbs[i+1]` 로 건너뛴다.
  * `W[]` 에 대해 충돌하지 않는다면 `abbs[i]` 가 답이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
```
