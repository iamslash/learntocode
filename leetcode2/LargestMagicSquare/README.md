# Problem

[Largest Magic Square](https://leetcode.com/problems/largest-magic-square/)

이차원 배열 `grid[][]` 가 주어진다. 다음과 같은 조건을 만족하는 정사각형을 magic square 라고 하자.

* 왼쪽 대각선의 원소들의 합과 오른쪽 대각선의 원소들의 합이 같다.
* 모든 행은 행들 구성하는 원소들의 합이 같다. 이것은 앞서 구한 대각선
  원소들의 합과 같다.
* 모든 열은 열을 구성하는 원소들의 합이 같다. 이것은 앞서 구한 대각선
  원소들의 합과 같다.
  
가장 큰 magic square 의 한변의 길이를 구하라.

# Idea

예를 들어 `grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]` 의 경우를 살펴보자.

```
7 1 4 5 6
2 5 1 6 4
1 5 3 3 2
1 2 7 3 4
```

다음과 같은 2D 배열을 선언하여 모든 행, 열, 왼쪽 대각선, 오른쪽 대각선의 부분합을 저장한다.

```java
		int h = grid.length, w = grid[0].length, maxLen = 0;
		int[][] rows = new int [h+1][w+1];
		int[][] cols = new int [h+1][w+1];
		int[][] dia1 = new int [h+1][w+1];
		int[][] dia2 = new int [h+1][w+1];
```

`int k` 를 선언하여 magic square 후보중 가장 큰 변의 길이를
저장한다. 예를 들어 앞서 언급한 예의 경우 `k = min(5, 4) = 4` 이다.

`int y, x` 를 선언하여 `k` 길이의 magic square 후보를 순회한다. 그리고
다음을 검증한다.

* 왼쪽 대각선의 합, 오른쪽 대각선의 합이 같은가?
* 모든 행의 합이 같은가?
* 모든 열의 합이 같은가?

too difficult

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(H^2W^2)
```
