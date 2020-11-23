# Problem

[Perfect Rectangle](https://leetcode.com/problems/perfect-rectangle/)

# Idea

사각형을 표현하는 2D 행렬 `R[][4]` 이 주어진다. `(R[i][0], R[i][1])`
는 left bottom position 이다. `(R[i][2], R[i][3])` 는 right top
position 이다.

`Set<String> posSet` 을 선언하여 작은 사각형들의 네 점을 저장한다.
`int[4] outPos` 을 선언하여 큰 사각형의 네 점을 저장한다.  `R[][]` 을
순회하며 다음을 반복한다.

* `int sumArea` 를 선언하고 작은 사각형들의 넓이를 더한다. 
* 작은 사각형의 left bottom pos, left top pos 과 right bottom pos,
  right top pos 을 `posSet` 에 저장한다. 이때 겹치는 점은 `posSet`
  에서 제거한다.
* 큰 사각형의 네 점 `outPos[4]` 를 계산한다.

모든 반복을 마치고 `outLbPos, outLbPos, outRbPos, outRtPos` 가
`posSet` 에 없다면 false 를 리턴한다. 작은 사각형들의 중복된 네 점을
제거 했으므로 `posSet` 의 길이는 4 이어야 한다.  `outArea` 와
`sumArea` 가 같다면 true 를 리턴한다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(HW) O(HW)
```
