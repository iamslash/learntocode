# Problem

[Minimize Maximum Value in a Grid](https://leetcode.com/problems/minimize-maximum-value-in-a-grid/)

2 차원 배열 `M[][]` 가 주어진다. `M[][]` 의 값들은 distinct 하다.
같은 행 혹은 같은 열의 크기 순서는 지키고 `max(M[][])` 가 최소가
되도록 값들을 변경해 보자. 이때 변경된 `M[][]` 의 값들은 distinct 할
필요는 없다.  그리고 변경된 `M[][]` 를 구하라.

# Idea

예를 들어 `[[3,1],[2,5]]` 의 경우를 살펴보자.

```
M:
3 1    3 1    2 1    2 1 
2 5    1 5    1 5    1 2
```

따라서 답은 다음과 같다. 

```
2 1
1 2
```

다음과 같은 자료구조를 선언한다.

* `PriorityQueue<Integer> pq` 를 선언하여 `M[][]` 를 삽입한다.  `M[][]`
의 오름차순을 유지한다.
* `int[] maxRows` 를 선언하여 행 마다 최대값을 저장한다. 
* `int[] maxCols` 를 선언하여 열 마다 최대값을 저장한다.

`max(M[][])` 의 값이 최소가 되려면 `1` 부터 하나씩 값을 늘려 `M[][]`
에 배정하면 된다. 이때 `M[y][x]` 와 같은 행 혹은 같은 열 값들과 크기 순서를 원래대로
유지해야 한다. 상하 좌우 서로 인접한 값들끼리의 순서가 중요하기 때문에
`max(maxRows[y], maxCols[x]) + 1` 를 `M[y][x]` 에 저장한다. 그리고
`maxRows[], maxCols[]` 를 업데이트 한다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(HW*lgHW) O(HW)
```
