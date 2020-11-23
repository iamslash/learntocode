# Problem

[Number of Burgers with No Waste of Ingredients](https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/)

# Idea

토마토 슬라이스의 개수 `T`, 치즈 슬라이스의 개수 `C` 가 주어진다. 점보
버거는 4 장의 토마토 슬라이스와 1 장의 치즈 슬라이스로 만들 수
있다. 스몰 버거는 2 장의 토마토 슬라이스와 1 장의 치즈 슬라이스로 만들
수 있다. 재료를 모두 소모하여 토마토, 치즈 슬라이스가 각각 0, 0 일 때
만들 수 있는 점보, 스몰 버거의 개수를 구하는 문제이다.

`T` 는 짝수 이어야 한다. `C * 2` 는 `T` 보다 작거나 같아야 한다.
`T <= C * 4` 이어야 한다.

그리고 다음과 같이 방정식을 만들 수 있다.

```
J   + S = C
J*2 + S = T/2

J = T/2 - C
S = C - J = C*2 - T/2
```

# Implementation

* [java8](Solution.java)

# Complexity

```
O(1) O(1)
```
