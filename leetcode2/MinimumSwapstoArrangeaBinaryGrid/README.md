# Problem

[Minimum Swaps to Arrange a Binary Grid](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/)

이차원 배열 `G[][]` 가 주어진다. 연속된 두 행의 모든 값을 교체할 수
있다. `G[0][0]` 시작하여 `G[n-1][n-1]` 로 끝나는 대각선을 그었을 때
위쪽 셀들의 값이 모두 0 이 되도록 해보자.  최소 교체 횟수를 구하는
문제이다. 만약 불가능하면 -1 리턴한다.

# Idea

예를 들어 `G = [[0,0,1],[1,1,0],[1,0,0]]` 를 살펴보자. 각 행마다 
오른쪽에 위치한 연속된 0 의 개수를 구해보자.

```
0 0 1    0
1 1 0    1
1 0 0    2
```

`vector<int> postZeroCnts` 를 선언하고 오른쪽에 위치한 연속된 0 을
저장한다.

이제 `postZeroCnts` 를 내림차순으로 정렬한 횟수를 구하면 된다.

이때 `postZeroCnts[i] >= n - i - 1` 이어야 한다. 그렇지 않으면 `-1` 을
리턴한다.

인덱스 `i` 를 이용하여 `postZeroCnts` 를 순회하며 다음을 반복한다.

* `postZeroCnts[i] >= n - i - 1` 이어야 한다. 최초로 만족하는 수를
  `A[k]` 라고 하자.
* `A[i]` 부터 순회하여 `A[k]` 를 찾는다.
* `A[k]` 부터 `A[i]` 까지 한칸씩 옮기면서 swap 한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
