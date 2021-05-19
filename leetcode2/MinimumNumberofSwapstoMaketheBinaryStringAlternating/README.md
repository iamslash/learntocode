# Problem

> [Minimum Number of Swaps to Make the Binary String Alternating](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/)

문자열 `s` 가 주어진다. `s` 는 `0, 1` 로 구성되어 있다.  연속된 숫자가
같지 않도록 `s` 의 각 원소들을 교체해 보자.  그 교체 횟수가 최소가
되도록 해보자. 최소 교체 횟수를 구하라.

# Idea

예를 들어 `s = "111000"` 의 경우를 살펴보자.

```
s: 1 1 1 0 0 0
   1 0 1 0 1 0
```

따라서 답은 `1` 이다.

`int cnt0, cnt1` 을 선언하여 각각 `0`, `1` 의 개수를 저장한다. `cnt0`
과 `cnt1` 의 차이가 1 을 넘어서면 문제의 조건을 만족시킬 수 없다.

`int miss0, miss1` 을 선언한다. `miss0` 에 `s` 의 홀 수 자리수의
숫자가 `0` 이 아닌 것의 개수를 저장한다. `miss1` 에 `s` 의 홀 수
자리수의 숫자가 `1` 이 아닌 것의 개수를 저장한다.

다음과 같은 3 가지 경우를 생각해 보자.

* `cnt0 == cnt1` 
  * `s` 의 길이는 짝 수이다.
  * `min(miss0, miss1)` 이 답이다.
* `cnt0 > cnt1`
  * `s` 의 길이는 홀 수이다.
  * `s` 의 홀 수 자리에 `0` 이 배치되어야 한다.
  * `miss0` 이 답이다.
* `cnt1 > cnt0`
  * `s` 의 길이는 짝 수이다.
  * `s` 의 홀 수 자리에 `1` 이 배치되어야 한다.
  * `miss1` 이 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
