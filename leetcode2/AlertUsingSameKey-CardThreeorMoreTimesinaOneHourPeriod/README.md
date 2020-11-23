# Problem

[Alert Using Same Key-Card Three or More Times in a One Hour Period](https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/)

문자열의 모음 `keyName[]`, 시간문자열의 모음 `keyTime[]` 이 주어진다.
`keyName[i]` 는 i-th 사람의 이름이다. `keyTime[i]` 는 i-th 사람의 출입
시각이다. 한시간 안에 3 번 이상 출입한 기록이 있는 있는 사람의
이름들을 구하라.

# Idea

시간의 형식은 `22:11` 이다. 이것을 `22 * 60 + 11` 과 같이 분을
의미하는 숫자로 바꾸는 것이 핵심이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
