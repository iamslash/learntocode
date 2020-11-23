# Problem

* [Shortest Word Distance III](https://leetcode.com/problems/shortest-word-distance-iii/)

# Idea

문자열의 모음 `W[]` 와 두 문자열 `a, b` 가 주어지면 `a, b` 의
가장 짧은 거리를 구하는 문제이다. 이때 `a = b` 일때 서로 다른 위치의
문자열만을 고려한다. 즉 거리가 `0` 이 될 수는 없다.

최소거리 `d` 와 두 인덱스 `l, r` 을 선언한다. 그리고 인덱스 `i` 를
이용하여 `W[]` 를 순회한다. `l` 은 `a` 의 인덱스 이고 `r` 은 `b` 의
인덱스이다. `d = min(d, abs(r-l))` 이다.

`l = -1, r = -1` 로 초기화 해두면 `~l && ~r` 을 이용해서 두 값이
모두 새롭게 저장되었는지 검증할 수 있다.

`a = b` 라면 `l, r` 이 서로 같지 않게 control flow 를 구성해야 한다.


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
