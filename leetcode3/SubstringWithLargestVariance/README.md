# Problem

[Substring With Largest Variance](https://leetcode.com/problems/substring-with-largest-variance/)

문자열 `s` 가 주어진다. 영문 소문자로만 구성되어 있다.

variance 는 다음과 같이 정의한다.

* `s` 의 subarray 들 중 임의의 두 문자의 개수차이를 말한다.

`s` 의 max variance 를 구하라.

# Idea

`abaaa` 의 variance 는 3 이다. `abcaaa` 의 variance 역시 3 이다.
임의의 두 문자를 선택하여 `s` 를 순회하는 방법을 사용해야 한다.

예르 들어 `s = "abaaa"` 인 경우를 살펴보자. 임의의 두문자 `a, b` 를
선택하고 `s` 를 순회한다. [kadane alogirhtm](/fundamentals/array/kadane/README.md) 으로 해결할 만 하다.

# Implementation

* [java11](MainApp.java)
* [py3](a.py)

# Complexity

```
O(N) O(N)
```
