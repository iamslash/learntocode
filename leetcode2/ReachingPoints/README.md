# Problem

[Reaching Points](https://leetcode.com/problems/reaching-points/)

좌표 `(a, b), (c, d)` 가 주어진다.  임의의 좌표 `(x, y)` 는 `(x, y+x)`
혹은 `(x+y, y)` 으로 변환할 수 있다. `(a, b)` 는 변환을 통해서 `(c,
d)` 가 될 수 있는지 검증하라.

# Idea

`(a, b)` 에서 출발해서 `(c, d)` 로 가야한다.  문제의 조건에 의해
좌표의 숫자들은 `[1,10^9]` 이다.  따라서 변환을 하면 항상 증가한다.
곧, `a <= c, b <= d` 이다.

또한 `(a, b)` 에서 출발하여 `(c, d)` 로 가는 것과 `(b, a)` 에서
출발하여 `(d, c)` 로 가는 것은 같다.

만약 `a == c && b > d` 이면 false 이다.  `b = b + a * k (0 <= k)` 이기
때문에 새로운 `b` 는 항상 `d` 보다 커지게 된다.  즉, 도착할 방법이
없다.

만약 `a == c && b <= d && b == d % a` 이면 true 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(?) O(?)
```
