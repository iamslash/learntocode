# Problem

[Cut Off Trees for Golf Event](https://leetcode.com/problems/cut-off-trees-for-golf-event/)

이차원 배열 `F[][]` 가 주어진다. `F[y][x]` 는 `0` 이면 갈 수 없고
`1` 이면 잔디이고 `2` 이상이면 나무의 높이이다. `F[0][0]` 에서 출발하여
나무들을 높이의 오름차순으로 베어보자. 모든 나무들을 베었을 때 최소 이동
거리를 구하라.

# Idea

`vector<vector<int>> heights` 를 선언하여 `F[y][x] > 1` 인 것에 대해
`{F[y][x], y, x}` 를 저장하고 오름차순으로 정렬한다. 이제 `F[0][0]`
에서 출발하여 `heights[i][1][2]` 까지 이동한다. `int step` 
을 선언하여 이동한 거리를 저장한다. 그리고 `ans` 에 더한다. 

이제 `heights[i][1][2]` 에서 출발하여 `heights[i+1][1][2]` 로 이동한다.

`vector<int>` 보다는 `pair<int, int>` 가 훨씬 성능이 좋다.

```
F: 1 2 3
   0 0 4
   7 6 5
   
   
1 - 2
2 - 3
3 - 4
4 - 5
5 - 6
6 - 7

The ans is 6
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(H^2W^2) O(HW)
```
