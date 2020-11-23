# Problem

[Strong Password Checker](https://leetcode.com/problems/strong-password-checker/)

# Idea

문자열 `s` 가 주어진다. 다음의 규칙을 만족하도록 `s` 에 문자를
추가,삭제,수정해보자. 그 최소 개수를 구하는 문제이다.

* It has at least 6 characters and at most 20 characters.
* It must contain at least one lowercase letter, at least one
  uppercase letter, and at least one digit.
* It must NOT contain three repeating characters in a row ("...aaa..."
  is weak, but "...aa...a..." is strong, assuming other conditions are
  met).

예를 들어 `s = aaaaabbbbbcccccdddddeeeee` 를 살펴보자.

`int needLower, needUpper, needDigit` 를 선언하고 각각 소문자가
필요한지 대문자가 필요한지 숫자가 필요한지를 저장한다. `0` 이면
필요없고 `1` 이면 필요하다. 그리고 `int needSum` 을 선언하여
`needLower + needUpper + needDigit` 를 저장한다.

만약 `s.size() < 6` 이면 쉽다. `needSum + max(0, 6 - (s.size() +
needSum))` 이 답이다. 표현식에서 `needSum` 은 이미 삽입,수정,삭제가
필요한 개수로 더하였기 때문에 `(s.size() + needSum)` 에서 한번 더
더해준다.

한가지 주의할 점이 있다. `aaaaaa` 의 경우 수정해야할 문자의 개수는
몇개일까?  `6` 개가 반복되니 `6 - 2` 에 의해 `4` 가 답일 것
같다. 그러나 `aabaab` 와 같이 `2` 개만 수정해도 된다.

`int change` 를 선언하여 `s` 의 반복된 문자열들 중 수정이 필요한
숫자를 저장한다.

이제 `6 <= s.size() <= 20` 이면 `max(needSum, change)` 가 답이다.

한편 `s.size() > 20` 이면 ???

This is really difficult to understand.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N^2) O(N)
```

# References

* [Simple Python solution](https://leetcode.com/problems/strong-password-checker/discuss/91008/Simple-Python-solution)
