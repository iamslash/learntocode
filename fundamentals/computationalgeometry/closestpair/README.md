# Problem

모든 점들중 가장 가까운 거리의 두 점을 조사하자.

# References

* [closest pair of points @ geeksforgeeks](http://www.geeksforgeeks.org/closest-pair-of-points/)
* [closest pair of points O(NlgN) @ geeksforgeeks](http://www.geeksforgeeks.org/closest-pair-of-points-onlogn-implementation/)

# Idea

`Brute Force` 전략을 구사한다면 `O(N^2)` 이다. `Divide Conquer` 전략을
구사한다면 `O(NlgN)` 으로 해결할 수도 있다.

![](/_img/closest_pair_of_points.png)

위 그림의 `(a)` 를 참고하자. 모든 점들을 `x` 의 오름차순으로 정렬하여 중간
점을 찾아 수직선 `l` 을 그어보자. 해답에 해당하는 두점 `(p1, p2)` 은 다음과 같이 세
경우에 존재 할 수 있다.

* 두점이 `l` 을 중심으로 왼쪽 그룹에 존재하는 경우
* 두점이 `l` 을 중심으로 오른쪽 그룹에 존재하는 경우
* `p1` 은 `l` 을 중심으로 왼쪽 그룹에 `p2` 는 `l` 을 중심으로 오른쪽 그룹에 존재하는 경우

첫째와 둘째의 경우에서 구한 최소 거리를 `δ` 라고 하자. 셋째의 경우 앞서
`y` 의 오름차순으로 정렬한 배열을 순회하면서 각 점과 `y` 좌표의 차이가
`δ` 보다 적은 점들과 비교하여 더욱 작은 거리를 얻어낸다. 

이때 위 그림의 `(b)` 를 참고하면 `2δ × δ` 사각형에 존재할 수 있는 점은
최대 `8` 개 이다. 따라서 한점에 대한 비교대상의 점들은 아무리 많아도
`7` 개를 넘을 수 없다.

만약 `2δ × δ` 사각형에 `9` 개 이상의 점들이 존재 할 수 있다면 `δ` 보다
작은 점들이 왼쪽 혹은 오른쪽 그룹에 존재하게 되어 최소 거리에 해당하는
`δ` 의 정의에 모순이 된다.

그리고 중복된 점들이 존재할 수 없다면 `2δ × δ` 사각형에 존재할 수
있는 점들의 수는 최대 `6` 개이다. 이때 비교 대상의 점들은 아무리 많아도
`5` 개를 넘을 수 없다.

시간 복잡도는 마스터 정리를 활용하여 다음과 같이 산출 할 수 있다.

```
T(N) = 2T(N/2) + O(N)
O(NlgN)
```

# Implementation

[c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```