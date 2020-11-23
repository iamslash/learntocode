# Problem

[Strange Printer II](https://leetcode.com/problems/strange-printer-ii/)

이차원 그래프 `G[][]` 가 주어진다. 또한 모든 값이 1 인 그래프 `S[][]`
가 존재한다. 다음의 규칙을 지키면서 `S[][]` 에 색을 칠한다.

* 프린터는 사각형을 구성하는 셀을 같은 색으로 칠할 수 있다.
* 한번 사용된 색을 다시 사용할 수 없다. 

`S[][]` 가 `G[][]` 가 될 수 있는지 검증하라.

# Idea

`vector<vector<int>> rects(61, {61, 61, 0, 0})` 를 선언하여 color 별로
`{min_y, min_x, max_y, max_x}` 를 저장한다.

`unordered_set<int> overlaps[61]` 를 선언하여 color 별로 겹치는 color 를 저장한다. 
만약 `overlaps[c] in overlaps[d]` 이고 `overlaps[d] in overlaps[c]` 이면 cyclinc dependency
가 존재하는 것이기 때문에 답은 false 이다.

`vector<int> visit` 을 선언하여 color 별 상황을 저장한다. `visit[c] ==
0` 이면 아직 방문을 하지 않은 것이고 `visit[c] == 1` 이면 방문중이고
`visit[c] == 2` 이면 방문을 끝낸 것이다.

예를 들어 다음과 같은 경우를 살펴보자.

```
graph:     
1 1 1 1      
1 2 2 1    
1 2 2 1    
1 1 1 1

overlaps: 1
          2

visit: 2 2
```

따라서 답은 true 이다.

또한 다음의 경우를 살펴보자.

```
graph:     
1 1 1 1      
1 2 2 1    
1 2 2 1    
1 1 1 2

overlaps: 1 2 
          2 1 

visit: 1 1 
```

따라서 답은 false 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(HW)
```
