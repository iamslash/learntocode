# Problem

[Boats to Save People](https://leetcode.com/problems/boats-to-save-people/)

# Idea

사람들의 모음 `P[]` 와 보트의 무게제한 `L` 이 주어진다.  보트는
두사람까지 탑승 가능하다. 모든 사람을 보트의 무게를 고려하여 한번에
탈출시키려면 필요한 보트의 개수를 구하는 문제이다.

two pointers 를 이용하여 해결해보자.  `P[]` 를 정렬한다. 인덱스 `i =
0, j = P.size() - 1` 를 사용하여 양쪽 끝에서 가운데 방향으로 두개씩
짝지어 보트에 태워보자.  `P[i] + P[j] <= L` 이면 둘다 태우면 되고
그렇지 않으면 `P[j]` 만 태운다.


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
