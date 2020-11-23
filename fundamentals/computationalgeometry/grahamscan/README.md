# Abstract

convex hull algorithm 들중 graham scan algorithm 에 대해 정리한다.

# References

* [6. convex hull @ algorithm](https://www.youtube.com/watch?v=-HuIMvYROls&list=PLe-ggMe31CTe_5WhGV0F--7CK8MoRUqBd&index=6)
* [Convex Hull | Set 2 (Graham Scan) @ geeksforgeeks](http://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/)

# Problem

점들의 모임 `P` 가 주어지면 모든 점들을 감싸는 다각형을 구하는 문제이다.

# Idea

모든 점들을 `y` 값의 오름차순으로 정렬하고 가장 작은 `y` 값을 갖는 점을
`p` 라고 하자. `y` 값이 같은 점이 두개 이상이라면 `x` 값이 가장 작은 점을
`p` 라고 하자. 정렬된 점들을 `p` 와 연결하여 만들어진 선분들의 극각도의
오름차순으로 다시 정렬한다. 정렬된 점들의 첫번째 점은 `convex hull` 이
명백하다.

정렬된 점들의 세번째 점부터 끝점까지 순회하면서 각 점을 `c` 라 하고 `c` 점
마다 다음과 같은 처리를 한다.  `c` 점 보다 정렬 순서가 이른 점을 순서대로
`a, b` 라고 할때 `ccw(a, b, c)` 가 `0` 보다 작으면 `b` 는 `convex hull` 이 아니다.
만약 `b` 가 `convex hull` 이 아니라면 `a` 를 `b` 로 교체하고 `a` 보다 이전의 점을
`a` 로 교체하여 다시 `ccw(a, b, c)` 가 `0` 보다 작은지 확인한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```