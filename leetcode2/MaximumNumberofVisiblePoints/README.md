# Problem

[Maximum Number of Visible Points](https://leetcode.com/problems/maximum-number-of-visible-points/)

점들의 모음 `P[]`, 각도 `angle`, 현재 위치 `L[]` 가 주어진다.
`(L[0],L[1])` 에서 anti clock wise 로 회전한다. `angle` 을 FOV (Field
Of View) 라고 했을 때 FOV 에 속하는 점들의 최대 개수를 구하라.

# Idea

`points` 를 순회하면서 [polar
angle](https://github.com/iamslash/learntocode/blob/247fe7dbe761956cd63073465cbaee4f3cfb19ee/fundamentals/computationalgeometry/vector/README.md)
의 오름차순으로 정렬한다. 이것을 `vector<int> angles` 에 저장한다.

```
polar angle (radian) = atan2(y, x)

pi (radian) = 180 (degree)
 1 (radian) = 180 (degree) / pi (radian)
 
polar angle (degree) = atan2(y, x) * 180 (degree) / pi (radian)
```

`(L[0], L[1])` 를 중심으로 회전해야 하기 때문에 `vector<int> angles2` 를
선언하여 `angles` 를 2 번 저장한다.

sliding window 를 이용하여 `angles2` 를 순회한다. `angle` 범위안에
속하는 점들의 최고 개수를 구한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
