# Problem

[Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/)

# Idea

트리의 루트노드 `u` 가 주어진다. 같은 값을 갖는 노드들의 길이 중 가장
긴 것을 구하는 문제이다.

예를 들어서 다음과 같은 트리를 살펴보자.

```
              5
             / \
            4   5
           / \   \
          1   1   5
```

`maxPathCnt` 를 선언하고 최대 길이를 저장한다. 같은 값을 갖는
노드들의 경로를 `uniquePath` 라고 하자.

0. 1 레벨의 `5` 를 방문 하자.

1. 왼쪽 자식 `4` 를 포함한 uniquePath 중 가장 긴 것을 `leftPathCnt` 에
저장하자. 마찬 가지로 오른쪽 자식 `5` 를 포함한 uniquePath 중 가장 긴
것을 `rightPathCnt` 에 저장하자.

2. 이제 1 레벨의 `5` 를 포함한 왼쪽 방향의 uniquePath 중 가장 긴 것을
`leftSameCnt` 에 저장한다. 이때 왼쪽 자식은 `4` 이므로 `leftSameCnt
=0` 이다.  마찬 가지로 `5` 를 포함한 오른쪽 방향의 uniquePath 중 가장
긴 것을 `rightSameCnt` 에 저장한다. 그리고 `leftSameCnt +
rightSameCnt` 를 `maxPathCnt` 와 비교하여 갱신한다.

모든 순회를 종료하면 `maxPathCnt` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [go](a.go)

# Complexity

```
O(N) O(lgN)
```
