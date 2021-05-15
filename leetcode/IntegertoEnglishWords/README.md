# Problem

> [Integer to English Words](https://leetcode.com/problems/integer-to-english-words/)

숫자 `num` 이 주어진다. 이것을 다음과 같이 English words 로 표기하라.

* `123`: `"One Hundred Twenty Three"`
* `12345`: `"Twelve Thousand Three Hundred Forty Five"`

# Idea

문제의 조건에 의해 `0 <= num <= 2^31 - 1` 이다. 

다음과 같은 규칙들을 발견할 수 있다.

* `4 byte` 는 `0 to 4,294,967,295` 만큼 표현이 가능하다.
* `num` 을 3 자리씩 끊어보자. 각 단위마다 다음과 같은 English words 가
  필요하다.
  * "Thousand",
  * "Million",
  * "Billion"
* `num` 을 3 자리씩 끊었을 때 분리된 숫자를 `subnum` 이라고
  하자. 왼쪽부터 `0, 1, 2` 번째 숫자라고 해보자.
  * `0` 번째 숫자를 표현하기 위해 `One, Two, .., Nine` 과 함께 다음과
  같은 숫자가 필요하다.
    * "Hundred"
  * `1, 2` 번째 숫자가 `20` 보다 작다면 `One, Two, .., Nine` 과 함께
    다음과 같은 English words 가 필요하다.
    * "Ten"
    * "Eleven"
    * "Twelve"
    * "Thirteen"
    * "Fourteen"
    * "Fifteen"
    * "Sixteen"
    * "Seventeen"
    * "Eighteen"
    * "Nineteen"
  * `1, 2` 번째 숫자가 `20` 보다 크거나 같다면 `One, Two, .., Nine` 과 함께
    다음과 같은 English words 가 필요하다.
    * "Ten"
    * "Twenty"
    * "Thirty"
    * "Forty"
    * "Fifty"
    * "Sixty"
    * "Seventy"
    * "Eighty"
    * "Ninety"    

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
