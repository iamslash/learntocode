# Problem

* [Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/)

# Idea

문자열의 모음 `S[]` 가 주어지면 문자들의 이동되는 형태에 따라
그룹핑하는 문제이다.

문자들의 이동되는 형태가 같으면 동일한 값을 리턴하는 `hash` 함수를 제작한다.
`S[]` 의 문자열들을 `hash` 값에 따라 맵을 이용하여 그룹핑하면 답이된다.

문자들 사이의 거리는 다음과 같이 구한다.

```
ba :  0 -  1 + 26 % 26 = 25
az : 25 -  0 + 26 % 26 = 25
ab :  1 -  0 + 26 % 26 = 1
za :  0 - 25 + 26 % 26 = 1
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
