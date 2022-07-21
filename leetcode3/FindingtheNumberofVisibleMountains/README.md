# Problem

[Finding the Number of Visible Mountains](https://leetcode.com/problems/finding-the-number-of-visible-mountains/)

좌표의 모음 `peaks[]` 가 주어진다. `peaks[i] = (x, y)` 이다.  `(x, y)`
를 중심으로 산 모양을 그린다. 이때 모서리의 기울기는 1 혹은 -1
이다. 더 높은 산 모양에 의해 가려지지 않는 점들의 개수를 구하라.

# Idea

예를 들어 `peaks = [[2,2],[6,3],[5,4]]` 의 경우를 살펴보자.

그림 생략...

따라서 답은 2 이다.

두개의 점 `(a, b), (c, d)` 이 있을 때 다음과 같은 중요한 규칙을 발견할
수 있다. 이때 `a <= c, b <= d` 가 되도록 정렬되어 있다.

```
a == c, b == d:    (a, b), (c, d) 는 둘다 서로 가린다.

a == c, b  < d:    (a, b) 는 (a, c) 에 의해 가려진다.

a  < c, b == d:    (a, b), (c, d) 는 둘다 서로 가지지 않는다.

a  < c, b  < d:    c - a <= d - b 이면 (a, b) 는 (c, d) 에 의해 가려진다.
```

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
