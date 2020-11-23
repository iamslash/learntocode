# Problem

[String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)

# Idea

문자열 `s` 가 주어진다. 이것을 정수로 바꾸는 문제이다.

인덱스 `i` 를 이용하여 `s` 를 순회한다. `int ans = 0` 를 선언하고 답을
저장한다. `bool neg = false` 를 선언하고 음수여부를 저장한다. `neg` 에
따라 계산하는 방법이 다르다. 또한 `INT_MAX, INT_MIN` 을 처리하는
방법도 다르다.

* `s[i]` 가 공백이면 무시한다.
* `s[i] == '+'` 이면 무시하고 `s[i] == '-'` 이면 `neg = true` 하자.
* 인덱스 `i` 를 이용하여 `s` 를 순회하며 다음을 반복한다.
  * `isdigit(s[i]) == false` 이면 반복문을 탈출한다.
  * `isdigit(s[i]) == true` 이면 `neg` 에 따라 다르게 계산한다.
  * `int dgt = s[i] - '0'`
    * `neg == true` 이면
      * `ans < (INT_MIN + dgt) * 10` 이면 `INT_MIN` 을 리턴한다.
      * `ans * 10 - dgt < INT_MIN` 이면 overflow 이기 때문이다.
    * `neg == false` 이면
      * `ans > (INT_MAX - dgt) * 10` 이면 `INT_MAX` 을 리턴한다.
      * `ans * 10 + dgt > INT_MAX` 이면 overflow 이기 때문이다.

모든 반복을 마치면 `ans` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
