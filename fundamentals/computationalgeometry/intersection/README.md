# Abstract

직선과 직선의 교차와 선분과 선분의 교차에 대해 정리한다.

# References

* [직선의 벡터방정식 @ 천재학습백과](http://koc.chunjae.co.kr/Dic/dicDetail.do?idx=22585)

# Line Intersection Point

직선을 한점과 방향 벡터로 표현할 수 있다. 이것을 [직선의 벡터
방정식](http://koc.chunjae.co.kr/Dic/dicDetail.do?idx=22585) 이라고
한다.

![](/_img/line_vector_eq.png)

```
직선 g 를 지나는 두점 a, b 와
직선 f 를 지나는 두점 c, d 가
주어졌을때 두직선 g 와 f 의 교차점 x 를 구해보자.

먼저 직선의 벡터 방정식을 알아보자.
직선 g 위의 무수히 많은 점 p 은 
한점 a, 방향 벡터 u, 임의의 실수 t 를 이용하여
다음과 같이 표현 가능하다.

p = a + tu

t 값을 적당히 설정하여 직선 g 의 무수히 많은 점 p 를
만들 수 있다는 의미이다. 이것을 직선 g 의
벡터 방정식이라고 한다.

이 때 g 의 방향벡터 u 와 f 의 방향벡터 v 는 다음과 같다.

u = b - a
v = d - c

그러므로 두직선을 벡터 방정식으로 표현하면 각각
a + pu, c + qv 이다.

두직선이 만나는 교차 점은 다음과 같이 표현 할 수 있다.
a + pu = c + qv

이것을 좌표 x, y 원소 별로 나누어 다음과 같은 연립 방정식을 얻을 수 있다.

a_x + p * u_x = c_x + q * v_x
a_y + p * u_y = c_y + q * v_y

q = (a_x - c_x + p * u_x) / v_x
q = (a_y - c_y + p * u_y) / v_y

(a_x - c_x + p * u_x) / v_x = (a_y - c_y + p * u_y) / v_y
(a_x - c_x + p * u_x) * v_y = (a_y - c_y + p * u_y) * v_x
p * (u_x * v_y - u_y * v_x) = ((c_x - a_x) * vy - (c_y - a_y) * vx)
p = ((c_x - a_x) * v_y - (c_y - a_y) * v_x) / (u_x * v_y - u_y * v_x)
p = ((c - a) × v) / (u × v)

x = a + p * u
x = a + ((c - a) × v) / (u × v) * u
x = a + ((c - a) × (d - c)) / ((b - a) × (d - c)) * (b - a)
```

다음은 네개의 점 `a, b, c, d` 가 주어지면 직선 `ab`, 직선 `cd` 의
교차점 `x` 를 구하는 구현이다.

```cpp
bool line_intersection(vector2 a, vector2 b,
                       vector2 c, vector2 d,
                       vector2& x) {
  double det = (b - a).cross(d - c);
  // in case of pararrel
  if (fabs(det) < EPSLION)
    return false;
  x = a + ((c - a).cross(d - c) / det) * (b - a);
  return true;
}
```

위의 내용을 다음과 같이 간단히 정리한다.

```
직선 f 를 지나는 점 a, b 와
직선 g 를 지나는 점 c, d 가 있을때
두직선 f 와 g 를 지나는 교점 x 는 다음과 같다.

f = a + p * u (f 는 직선위의 무수히 많은 점, u 는 방향벡터 b - a)
g = c + q * v (g 는 직선위의 무수히 많은 점, v 는 방향벡터 d -c)
x = a + p * u (a 는 점 p는 실수 u는 방향 벡터)
p = ((c - a) × v) / (u × v)
x = a + ((c - a) × v) / (u × v) * u
```

# Segment Intersection Point

선분 f 의 끝점 a, b 와 선분 g 의 끝점 c, d 가
주어 졌을때 두 선분의 교차점 x 을 구해보자.

선분 f 를 포함하는 직선과 선분 g 를 포함하는 직선의
교차점 x 를 구한다. 만약 x 가 있다면 x 가 f 와 g 에 포함되는지 확인한다.
만약 x 가 없다면 f 와 g 는 평행하다 곧 f 와 g 는 한 직선위에 있다.

f 와 g 가 평행한다면 다음과 같이 네가지 경우를 생각해 볼 수 있다.

두 선분이 서로 겹치지 않는다.
두 선분이 한 점에서 닿는다.
두 선분이 겹친다.
한 선분이 다른 선분 안에 포함된다.

첫번째 경우를 제외하면 임의의 교차점이 존재한다.

다음은 언급한 알고리즘을 구현한 것이다.

```cpp
bool pararrel_segments(vector2 a, vector2 b,
                         vector2 c, vector2 d,
                         vector2& p) {
  if (b < a)
    std::swap(a, b);
  if (d < c)
    std::swap(c, d);
  // not on the same line, not overlapping case
  if (ccw(a, b, c) != 0 || b < c || d < a)
    return false;
  // two segments overlap
  if (a < c)
    p = c;
  else
    p = a;
  return true;
}

bool in_bounding_rectangle(vector2 p, vector2 a, vector2 b) {
  if (b < a)
    std::swap(a, b);
  return p == a || p == b || (a < p && p < b);
}

bool segment_intersection(vector2 a, vector2 b,
                         vector2 c, vector2 d,
                         vector2& p) {
  if (!line_intersection(a, b, c, d, p))
    return pararrel_segments(a, b, c, d, p);
  return in_bounding_rectangle(p, a, b) &&
      in_bounding_rectangle(p, c, d);
}
```

# Segment Intersection 

선분 `f` 의 양 끝점에 해당하는 `a, b` 와 
선분 `g` 의 양 끝점에 해당하는 `c, d` 가 주어졌을때
두 선분이 교차 하는지 판별해보자.

두 선분 `f, g` 가 같은 직선위에 있는 경우 두 선분이 겹치기 위해서는
`ccw(a, b, c), ccw(a, b, d), ccw(c, d, a), ccw(c, d, b)` 가 `0` 이고 한
선분의 끝점이 다른 선분에 포함되어 있어야 한다.

두 선분 `f, g` 가 같은 직선위에 있지 않은 경우 두 선분이 겹치기 위해서는
`ccw(a, b, c)` 와 `ccw(a, b, d)` 의 부호가 다르고 `ccw(c, d, a)` 와 `ccw(c, d,
b)` 가 부호가 달라야 한다.

```cpp
bool segment_intersect(vector2 a, vector2 b,
                       vector2 c, vector2 d) {
  double ab = ccw(a, b, c) * ccw(a, b, d);
  double cd = ccw(c, d, a) * ccw(c, d, b);
  // two segments on the same line
  // end point overlap
  if (ab == 0 && cd == 0) {
    if (b < a)
      std::swap(a, b);
    if (d < c)
      std::swap(c, d);
    return !(b < c || d < a);
  }
  return ab <= 0 && cd <= 0;
}
```

# Implementation

* [c++11](a.cpp)