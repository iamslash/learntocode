# Problem

[PINBALL @ algospot](https://algospot.com/judge/problem/read/PINBALL)

# Idea

지름이 1인 공을 지름이 0인 점으로 변형하면 구현이 수월하다. 장애물들의
지름을 1씩 증가하자. 점이 이동하는 문제로 변형되었다.

점이 시간 t에 대해 이동한 거리를 f(t)라고 하자. f(t)는 다음과 같다.
p는 시작점의 위치벡터이고 q는 방향벡터이다.

```
f(t) = p + tq
```

장애물의 중심점을 c라 하고 반지름의 길이를 r이라 하자.  현재 점의 현재
위치 p에서 모든 장애물들과의 교점 x을 구하면 시간 t를 알수 있고 t가
가장 작은 값의 장애물이 충돌하는 장애물이 된다.

```
|c - f(t)| = r
(c - f(t))(c - f(t))            = r^2 (a^2 = |a||a| 이므로 양변 제곱)
c^2 - 2cf(t) + f(t)^2           = r^2
c^2 - 2·c·(p + tq) + (p + tq)^2 = r^2
c^2 - 2·c·p -2·c·q·t + p^2 + 2·p·q·t + q·q·t^2 = r^2
q·q·t^2 + 2(p-c)·q·t + c·c + p·p - 2·c·p - r·r = 0
```

일단 장애물과 부딛히면 장애물과의 교점을 x라고 반사벡터를 r이라 할때
f(t)는 다시 다음과 같이 표현할 수 있다.

```
f(t) = x + tr
     = p + tq
```

## 반사벡터 구하기

![](../_img/reflect_vector.png)

그림과 같이 입사 벡터 P를 법선 벡터 n에 투영한 벡터를 n(-P·n)이라고 할때
반사 벡터 R은 다음과 같다.

```
R = P + 2·n(-P·n)
```

입사 벡터를 P라하고 장애물의 중심을 c, 입사 벡터와 장애물의 교점을 x라 할때
반사 벡터의 구현은 다음과 같다.

```cpp
Vector2 reflect(Vector2 P, vector2 c, vector2 x) {
  Vector2 r = P - P.project(x - c) * 2;
  return r.normalize();
}
```

# Implementation

[src](a.cpp)

# References

* [반사벡터 @ tistory](http://ifyouwanna.tistory.com/entry/%EB%B0%98%EC%82%AC%EB%B2%A1%ED%84%B0)