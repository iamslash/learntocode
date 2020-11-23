# Problem

[Masking Personal Information](https://leetcode.com/problems/masking-personal-information/)

# Idea

문자열 `s` 가 주어진다. `s` 가 이메일 혹은 전화번호인지 구분하고
일부정보를 마스킹한 문자열을 구하는 문제이다.

먼저 `s` 에 `@` 가 있는지 검사한다. 있다면 이메일이다. 모두 소문자로
바꾼다. 그리고 `@` 앞 아이디의 첫 문자와 마지막 문자 사이를 `*****` 로
채우자.

`s` 에 `@` 가 없다면 전화번호 이다. 숫자를 제외한 문자들을 모두
지운다.  `10` 개에서 `13` 개 사이일 것이다. 숫자의 개수에 따라
국가코드를 `+*-, +**-, +***-` 를 추가한다. 마지막 4 개의 숫자를
제외하고 모두 `*` 으로 바꾼다. `std::regex_replace` 를 이용하면
regular expression 으로 쉽게 숫자만 남길 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
