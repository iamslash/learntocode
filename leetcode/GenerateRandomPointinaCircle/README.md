# Problem

[Generate Random Point in a Circle](https://leetcode.com/problems/generate-random-point-in-a-circle/)

# Idea

원의 중심 좌표 `(cx, cy)` 와 반지름 `r` 이 주어진다. 원의 내부에
속하는 임의의 점을 랜덤하게 생성하는 문제이다.

`rand() / RAND_MAX` 는 `[0..1]` 의 값이다. 이것에 `2` 를 곱하고 `1.0`
을 빼면 `[-1..1]` 의 값을 얻을 수 있다.  이것을 다시 `r` 에 곱하면
`[-r..r]` 의 값을 얻을 수 있다.

한번은 `dx` 에 한번은 `dy` 에 저장한다. `(dx, dy)` 는 원점을 중심으로
하는 반지름이 `2r` 인 정사각형 내부의 점이다. `dx*dx + dy*dy <= r*r`
일 때까지 `dx, dy` 를 생성하자. 그러면 `(cx+dx, cy+dy)` 가 답이다.

이렇게 체택될때까지 랜덤시도하는 것을 reject sampling 이라고 한다.

사각형의 영역에서 원의 영역의 점이 나올 확률은 `원의 넓이 / 사각형의
넓이` 와 같다. 즉 `pi * r^2 / 2r * 2r = pi / 4 = 3.14 / 4 = 0.785`
이다. 시도해 볼만한 확률이다.

# Implmentation

* [c++11](a.cpp)

# Complexity

```
O(1) O(1)
```
