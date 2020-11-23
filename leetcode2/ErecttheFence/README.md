# Problem

[Erect the Fence](https://leetcode.com/problems/erect-the-fence/)

좌표의 모음 `P[][]` 가 주어진다. `P[0] = x, P[1] = y` 이다.  모든 점을
포함하는 최소의 다각형 convex hull 을 구하라.

# Idea

[Convex Hull | Monotone chain algorithm @ geeksforgeeks](https://www.geeksforgeeks.org/convex-hull-monotone-chain-algorithm/)
를 참고한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
