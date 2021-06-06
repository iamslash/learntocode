- [Abstract](#abstract)
- [rotate](#rotate)

---

# Abstract

two pointers 로 문제를 해결할 때 사용할 수 있는 loop pattern 을 정리한다.

# rotate

`mat[n][n]` 가 있다고 해보자. matrix 를 시계방향으로 90 도씩 회전하는 전략이다.

| angle | x       | y       |
| ----- | ------- | ------- |
| 0     | `x`     | `y`     |
| 90    | `x`     | `n-y-1` |
| 180   | `n-y-1` | `n-x-1` |
| 270   | `n-x-1` | `y`     |

* [L](/leetcode2/DetermineWhetherMatrixCanBeObtainedByRotation/) | [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)
